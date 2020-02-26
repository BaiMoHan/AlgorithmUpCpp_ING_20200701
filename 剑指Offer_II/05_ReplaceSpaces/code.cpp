//length为字符数组string的总容量
void ReplaceBlank(char string[],int length)
{

    if(string==nullptr||length<=0)
        return;

    
    int originalLength=0;//string的长度
    int numberOfBlank=0;//空格个数
    int i=0;
    while (string[i]!='\0')
    {
        ++originalLength;
        if(string[i]==' ')
            ++numberOfBlank;
        ++i;
    }
    int newLength=originalLength+numberOfBlank*2;//替换后的长度
    if(newLength>length)
        return ;

    int indexOfOriginal=originalLength;
    int indexOfNew=newLength;
    while(indexOfOriginal>=0&&indexOfNew>indexOfOriginal)
    {
        if(string[indexOfOriginal]==' ')
        {
            string[indexOfNew--]='0';
            string[indexOfNew--]='2';
            string[indexOfNew--]='%';
        }else
        {
            string[indexOfNew--]=string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}