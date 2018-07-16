#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MIN(x, y) (x < y ? x : y)

typedef struct
{
	char title[100];
	char author[100];
	// 0 in library, 1 borrowed, 2 returned
	char status = 0;
} book;

bool sort(book a, book b)
{
	for(int i = 0; i < MIN(strlen(a.author), strlen(b.author)); i++)
	{
		if(a.author[i] == b.author[i]) continue;
		return a.author[i] < b.author[i];
	}
	for(int i = 0; i < MIN(strlen(a.title), strlen(b.title)); i++)
	{
		if(a.title[i] == b.title[i]) continue;
		return a.title[i] < b.title[i];
	}
	return true;
}

int main(void)
{	
	std::vector<book> books;

	// Read books
	while(1)
	{
		char s[100];
		scanf("%[^\n]%*c", s);

		if(strcmp(s, "END") == 0)
			break;

		book a;

		// Title
		int i = 0;
		for(; i < strlen(s); i++)
		{
			if(i > 1 && s[i-1] == '"')
			{
				a.title[i] = '\0';
				i += 4;
				break;
			}
			a.title[i] = s[i];
		}

		// Author
		int j = 0;
		for(; i + j < strlen(s); j++)
			a.author[j] = s[i + j];
		a.author[j] = '\0';

		books.push_back(a);
	}
	
	// Sorting
	std::sort(books.begin(), books.end(), sort);

	// Read input
	while(1)
	{
		char instruction[10];
		scanf("%s", instruction);
		
		if(strcmp("END", instruction) == 0)
			break;

		if(strcmp("BORROW", instruction) == 0 || strcmp("RETURN", instruction) == 0)
		{
			char book[100];
			scanf("%[^\n]%*c", book);
			
			int i = 1;
			for(; i < strlen(book); i++)
				book[i - 1] = book[i];
			book[i - 1] = '\0';

//			printf("\t%s\n", book);

			for(int i = 0; i < books.size(); i++)
			{
				if(strcmp(books[i].title, book) == 0)
				{
					books[i].status = strcmp("BORROW", instruction) == 0 ? 1 : 2;
					break;
				}
//				else
//					printf("\tVECTOR: '%s' INPUT: '%s' CMP:%d\n", books[i].title, book, strcmp(books[i].title, book));
			}
		}

		if(strcmp("SHELVE", instruction) == 0)
		{
			for(int i = 0; i < books.size(); i++)
			{
//				printf("\t%d\n", books[i].status);
				if(books[i].status != 2) continue;
				for(int j = i - 1;; j--)
				{
					if(j < 0)
					{
						printf("Put %s first\n", books[i].title);
						break;
					}
					if(books[j].status == 0)
					{
						printf("Put %s after %s\n", books[i].title, books[j].title);
						break;
					}
				}
				books[i].status = 0;
			}
			printf("END\n");
		}
	}

//	for(int i = 0; i < books.size(); i++)
//		printf("%s by %s\n", books[i].title, books[i].author);

	return 0;
}
