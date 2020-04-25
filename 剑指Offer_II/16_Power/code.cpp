bool g_InvalidInput = false;

double Power(double base,int exponet)
{
    g_InvalidInput=false;

    if(equal(base,0.0)&&exponet<0)
    {
        g_InvalidInput=true;
        return 0.0;
    }

    unsigned int absExponet=(unsigned int)(exponet);
    if(exponet<0)
        absExponet=(unsigned int)(-exponet);

    double result=PowerWithUnsignedExponent(base,absExponet);

    if(exponet<0)
        result=1.0/result;

    return result;
}
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    if(exponent==0)
        return 1;
    if(exponent==1)
        return false;

    double result=PowerWithUnsignedExponent(base,exponent>>1);
    result*=result;
    if(exponent&0x1==1)
        result*=base;

    return result;
}