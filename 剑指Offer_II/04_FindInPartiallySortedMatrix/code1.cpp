//从右上角开始比对
bool Find(int *matrix,int rows,int columns,int number)
{
    bool found=false;

    if (matrix!=nullptr&&rows>0&&columns>0)
    {
        int row=0;
        int column=columns-1;
        while (row<rows&&column>=0)
        {
            if(matrix[row*columns+column]==number)
            {
                found=true;
                break;
            }
            else if (matrix[row*columns+column]>number)
            {
                column--;
            }else
            {
                ++row;
            }
            
            
        }
        return found;
        
    }
    
}