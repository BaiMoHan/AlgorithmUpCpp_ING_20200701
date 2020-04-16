bool hasPath(char* matrix,int rows,int cols,char* str)
{
    if(matrix==nullptr||rows<1||cols<1||str==nullptr)
        return false;
    
    bool *vistied=new bool[rows*cols];
    memset(vistied,0,rows*cols);

    int pathLength=0;
    for(int row=0;row<rows;row++)
    {
        for(int col=0;col<cols;col++)
        {
            if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,vistied))
                return true;
        }
    }
    delete[] vistied;

    return false;
}

bool hasPathCore(const char* matrx,int rows,int cols,int row,int col,const char* str,int&pathLength,bool* visitied)
{
    if(str[pathLength]=='\0')
        return true;

    bool hasPath=false;

    if(row>=0&&row<rows&&col>=0&&col<cols&&matrx[row*col+col]==str[pathLength]&&!visitied[row*cols+col])
    {
        ++pathLength;
        visitied[row*cols+col]=true;
        hasPath=hasPathCore(matrx,rows,cols,row,col-1,str,pathLength,visitied)||hasPathCore(matrx,rows,cols,row-1,col,str,pathLength,visitied)||hasPathCore(matrx,rows,cols,row,col+1,str,pathLength,visitied)||hasPathCore(matrx,rows,cols,row+1,col,str,pathLength,visitied);
        if(!hasPath)
        {
            --pathLength;
            visitied[row*cols+col]=false;
        }
    }
    return hasPath;
}