int kadane_algorithm(int[] array, int size)
{
    int max = 0, sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += array[i];
        if(sum > max)
            max = sum;
        if(sum < 0)
            sum = 0;
    }

    return max;
}
