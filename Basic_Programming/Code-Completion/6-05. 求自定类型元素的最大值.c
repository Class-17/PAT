ElementType Max(ElementType S[], int N )
{
    ElementType maximum = S[0];
    for(int i = 1; i < N; i++)
        if(S[i] > maximum)
            maximum = S[i];
    return maximum;
}