int w, h;
int table[w][h];

void read_input()
{
    for(int j = 0; j < h; j++)
    for(int i = 0; i < w; i++)
    {
        scanf("%d", &table[i][j]);
        if(i > 0)
            table[i][j] += table[i - 1][j];
        if(j > 0)
            table[i][j] += table[i][j - 1];
        if(i > 0 && j > 0)
            table[i][j] -= table[i - 1][j - 1];
    }
}

int max()
{
    int max = -100000000, sum = 0;
    for(int i = 0; i < w; i++) for(int j = 0; j < h; j++)
    for(int k = i; k < w; k++) for(int l = j; l < h; l++)
    {
        sum = table[k][l];
        if(i > 0)
            sum -= table[i - 1][l];
        if(j > 0)
            sum -= table[k][j - 1];
        if(i > 0 && j > 0)
            sum += table[i - 1][j - 1];
        if(sum > max)
            max = sum;
    }
    return max;
}
