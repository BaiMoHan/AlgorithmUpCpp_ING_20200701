//从左下角开始比对
bool Find(int *matrix,int rows,int columns,int number)
{
    bool found=false;

    if (matrix!=nullptr&&rows>0&&columns>0)
    {
        int row=rows-1;
        int column=0;
        while (row>=0&&column<columns)
        {
            if(matrix[row*columns+column]==number)
            {
                found=true;
                break;
            }
            else if (matrix[row*columns+column]>number)
            {
                row--;
            }else
            {
                ++column;
            }
        }
        return found;
        
    }
    
}