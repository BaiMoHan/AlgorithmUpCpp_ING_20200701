bool scanUnsignedInteger(const char** str)
{
    const char* before=*str;
    while(**str!='\0'&&**str>='0'&&**str<='9')
        ++(*str);
    //当str中存在若干0-9的数字时，返回true
    return *str>before;
}
bool scanInteger(const char** str)
{
    if(**str=='+'||**str=='-')
        ++(*str);
    return scanUnsignedInteger(str);
}
bool isNumeric(const char* str)
{
    if(str==nullptr)
        return false;

    bool numeric=scanInteger(&str);
    //如果出现'.'，接下来为小数部分
    if(*str=='.')
    {
        ++str;
        numeric=scanUnsignedInteger(&str)||numeric;
    }
    if(*str=='e'||*str=='E')
    {
        ++str;
        numeric=numeric&&scanInteger(&str);
    }
    return numeric&&*str=='\0';
}