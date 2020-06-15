void Permutatio(char* pStr,char* pBegin)
{
    if(*pBegin=='\0')
    {
        printf("%s\n",pStr);
    }else
    {
        for(char* pCh=pBegin;*pCh!='\0';++pCh)
        {
            char temp=*pCh;
            *pCh=*pBegin;
            *pBegin=temp;
            Permutation(pStr,pBegin+1);
            temp=*pch;
            *pch=*pBegin;
            *pBegin=temp;
        }
    }
}

void Permutation(char* pStr)
{
    if(pStr==nullptr)
        return;
    Permutation(pstr,pStr);
}