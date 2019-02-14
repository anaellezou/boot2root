#include <stdio.h>
#include <stdlib.h>

//                 "1 2 3 4 5 6", "Public speaking is very easy."
int		read_six_numbers(char *input, int *buffer)
{
	int count = sscanf(input, "%d %d %d %d %d %d", &buffer[0], &buffer[1], &buffer[2], &buffer[3], &buffer[4], &buffer[5]);
	if (count < 6) {
		explode_bomb();
	}
}



// each number must increase
void	phase_2(char *input)
{
	int counter;
	int buffer[6];

	counter = 1;

	read_six_numbers(input, buffer);
	if (buffer[0] != 1) {
		explode_bomb();
	}

	while(counter <= 5) {
		if (buffer[counter-1]*2 != buffer[counter]) {
			explode_bomb();
		}
		counter++;
	}
}

void	phase_3(char *input) {
	int int1;
	int int3;
	char char2;

	int count = sscanf(input, "%d %c %d", &int1, &char2, &int3);
	if (count < 4) {
		explode_bomb();
	}

	if (int1 > 7) {
		explode_bomb();
	}

	char ref;
	
	switch (int1)
	{
		case 0:
			ref = 0x71;
			if (int3 != 0x309) {
				explode_bomb();
			}
		case 1:
			ref = 0x62;
			if (int3 != 0xd6) {
				explode_bomb();
			}
		case 2:
			ref = 0x62;
			if (int3 != 0x2f3) {
				explode_bomb();
			}
		case 3:
			ref = 0x6b;
			if (int3 != 0xfb) {
				explode_bomb();
			}
		case 4:
			ref = 0x6f;
			if (int3 != 0xa0) {
				explode_bomb();
			}
		case 5:
			ref = 0x74;
			if (int3 != 0x1ca) {
				explode_bomb();
			}
		case 6:
			ref = 0x76;
			if (int3 != 0x30c) {
				explode_bomb();
			}
		case 7:
			ref = 0x62;
			if (int3 != 0x20c) {
				explode_bomb();
			}
	}

	if (ref != char2) {
		explode_bomb();
	}

}

int func4(int number) {
	if (number <= 1) {
		return (1);
	}
	return (func4(number-1) + func4(number-2));
}

void phase_4(char *input) {
	int nb;
	int count;

	count = sscanf(input, "%d", &nb);
	if (count != 1 || nb <= 0) {
		explode_bomb();
	}

	if (func4(nb) != 0x37) {
		explode_bomb();
	}
}

void phase_5(char *input) {
	int		len;
	char	buffer[6];
	char	*str;
	int		index;

	len = string_length(input);
	if (len != 6) {
		explode_bomb();
	}

	str = "isrveawhobpnutfg\260\001";

	
	for(size_t i = 0; i < len; i++)
	{
		index = input[i];
		buffer[i] = str[index];
	}

	if (buffer != "giants") {
		explode_bomb();
	}
}

void phase_6(char *input) {
	int node;
	int counter;
	int counter2;
	int     buffer[6];

	node = 0xfd;
	counter = 0;
	read_six_numbers(input, buffer);
	
	// numbers are all different & below 6.

	while(counter <= 5){
		counter2 = counter+1;
		if (buffer[counter] > 6) {
			explode_bomb();
		}
		while(counter2 <= 5) {
			if (buffer[counter] == buffer[counter2]) {
				explode_bomb();
			}
			counter2++;
		}
		counter++;
	}

	int		counter4;
	int		buffer2[] = {253, 725, 301, 997, 212, 432};
	int		*tmp;
	int		buffer_tmp[6];

/*	
**	{253, 725, 301, 997, 212, 432}
**	{ 1 , 2  , 3  , 4  , 5  , 6  }
**
**	Sort by buffer_input
*/
	for(int i = 0; i <= 5; i++)
	{
		counter4 = 1;
		if (counter4 < buffer[i])
		{
			tmp = buffer2;
			while(counter4 < buffer[i])
			{
				tmp++;
				counter4++;
			}
		}
		buffer_tmp[i] = *tmp;
		i++;
	}

	for (int i = 0 ; i <= 5 ; i++)
	{
		buffer2[i] = buffer_tmp[i];
		i++;
	}

	// Check if is it sort
	for (int i = 0 ; i <= 5 ; i++)
	{
		if (buffer2[i] < buffer2[i + 1])
			expode_bomb();
	}
}

// init bombe, launch all phase with phase_defused
int main(int ac, char **av)
{
	char *str;

	str = read_line();

	phase_2(str);
	phase_defused();
}