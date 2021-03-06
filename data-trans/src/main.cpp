// The MIT License (MIT)
//
// Copyright (c) 2015 THINGER LTD
// Author: alvarolb@gmail.com (Alvaro Luis Bustamante)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "thinger/thinger.h"
#include "stdio.h"
#include "stdlib.h"

#define USER_ID             "Change IT"
#define DEVICE_ID           "Change IT"
#define DEVICE_CREDENTIAL   "Change IT"
int num = 0;
int getNum(){
	FILE *fptr;
	if ((fptr = fopen("program.txt","r")) == NULL)
	{
		printf("Error! opening file");
		// Program exits if the file pointer returns NULL.
		exit(1);
	}
	fscanf(fptr,"%d", &num);
	// printf("Value of n=%d", num);
	fclose(fptr);

	return num;
}

int main(int argc, char *argv[])
{
	
	
	
	thinger_device thing(USER_ID, DEVICE_ID, DEVICE_CREDENTIAL);
	thing["sensor"] >> [](pson& out){
	out = getNum();
	};
	
	thing.start();
	return 0;
}
