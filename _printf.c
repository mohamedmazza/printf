#iclude <main.h>
void print_buffer(char buffer[],int *buff_ind);

int _print(const char *format,...)
{
	int a,printed = 0,printed_chars = 0;
	int flags,width,precision,size, buff_int =0;
	va_list list;
	char buffer[BUFF_SIZE];

	if(format == NULL)
		return(-1);

	va_start(list,format);

	for(i = 0;format && format[i] !='\0';a++)
	{
		if (format[a] !='%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer,&buff_ind);
			printed_char++;
		}
		else
		{
		  print_buffer(buffer,&buff_ind);
	  	  flags = get_flags(format,&a);
		  width = get_width(format,&a,list);
		  precision = get_precision(format,&a,list);
		  size = get_size(format,&a);
		  ++a;
		  printed = handle_print'format,&a,list,buffer,flags,width,precision,size);
		  if(printed == -1)
			  return (-1);
		  printed_chars += printed;

		}
	}

