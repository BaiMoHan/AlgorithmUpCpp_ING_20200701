bool duplicate(int numbers[],int length,int* duplication)
{
	if(number==nullptr||length<=0)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if(numbers[i]<0||numbers[i]>length-1)
			return false;
	}

	for (int i = 0; i < length; i++)
	{
		while (numbers[i]!=i)
		{
			if(numbers[i]==numbers[numbers[i]])
			{
				*duplication=numbers[i];
				return false;
			}
			
			//交换
			int temp=numbers[i];
			numbers[i]=numbers[temp];
			numbers[temp]=temp;
		}
		
	}
	
	
 } 
