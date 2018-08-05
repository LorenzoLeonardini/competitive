#include <stdio.h>
#include <bitset>

int main(void)
{
	int ot, rt;
	while(1)
	{
		scanf("%d %d", &ot, &rt);
		if(ot == 0 && rt == 0) break;

		std::bitset<1000001> cal;

		bool conflict = false;

		while(ot--)
		{
			int start, end;
			scanf("%d %d", &start, &end);
			if(conflict) continue;
			for(int i = start; i < end; i++)
			{
				if(cal[i])
				{
					conflict = true;
					break;
				}
				cal[i] = 1;
			}
		}

		while(rt--)
		{
			int start, end, rep;
			scanf("%d %d %d", &start, &end, &rep);
			if(conflict) continue;
			while(start < 1000001)
			{
				for(int i = start; i < end; i++)
				{
					if(i > 1000000) break;
					if(cal[i])
					{
						conflict = true;
						break;
					}
					cal[i] = 1;
				}
				if(conflict) break;
				start += rep;
				end += rep;
			}
		}

		printf(conflict ? "CONFLICT\n" : "NO CONFLICT\n");
	}

	return 0;
}
