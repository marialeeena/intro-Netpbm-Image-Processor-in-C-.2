#include <stdio.h>

int main() 
{
  int P,num,R,G,B,a,b,N,M,grey,max,com,ch,blackwhite,i,j,teliko,count,pixels,pixels2,br;
  P=getchar();            /*magic number is in ascii so the char P is 1 byte,so we can read it with 1 getchar*/
  if (P!='P')            /*if the file doesnt have the char P it lacks the necessary data so we must stop the program*/
  {
    fprintf(stderr, "1.Input error\n");
    return 1;             
  }
  putchar(P);              /*in order for the output file to be have all the necessary data we need to manually put them into it*/     
  num=getchar();          /*magic number is in ascii so the char number is 1 byte,so we can read it with 1 getchar*/
  if (num<'1'||num>'6')  /*if the file doesnt have the char num or if itsnot in the range 1-6 it lacks the necessary data so we must stop the program*/
  {
    fprintf(stderr, "2.Input error\n");   /*print an error message in the surrounding environment*/
    return 1;                                            /*stop the program*/
  }
  putchar(num-1);                                       /*the output file is always one number less than the input*/

  com=0;                                               /*in the beginning we have 0 comments*/
  a=getchar();                                        /*read white character in ascii format, as it exists in the input file*/
  if (a!='\n' && a!='\t' && a!=' ')                  /*we need to have at least one white character*/
  {
    fprintf(stderr, "3.Input error\n");
    return 1;
  }
  putchar(a);                                        /*put at least one white character in the output file*/                  
  while ((a=='\n' || a=='\t' || a==' ') || com==1)  /*while we read white chars, or whatever chars if we are in a comment, get in the loop*/
  {
    a=getchar(); 
    if (a=='#')                                       /*start of comment*/
    {
      com=1;                                        /*we are now in a comment*/
    } 
    else if (a=='\n')                             /*end of comment*/
    {
      com=0;                                    /*we are now out of a comment*/
    }
    if (com==0)                               /*if we are out of a comment then the only acceptable chars are whites or numbers (for the width)*/
    {
      if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9'))
      {
        fprintf(stderr, "4.Input error\n");
        return 1;
      }
    } 
  }
  N=0;              /*initial value of width is 0*/
  b=a;             /*for sure the last char we read was a number,so we put it in the b variable,                                                
                   because if it was a white the loop wouldnt have stopped and everything else would be an error*/
  putchar(b);     /*put the ascii format of each width digit in the output*/
  while (b!='\n' && b!='\t' && b!=' ')                           /*while no whites, we are reading the width*/
  {
    N=(N*10) + (b -'0');                                       /*converting the ascii format digits in a whole decimal number*/
    b=getchar();
    if ((b<'0' || b>'9') && (b!='\n' && b!='\t' && b!=' '))  /*the ony acceptable chars here are numbers or whites (for the next white space)*/
    {
      fprintf(stderr, "5.Input error\n");
      return 1;
    }
    putchar(b);
  }
  a=b;                                                            /*for sure the last char we read was a white,so we put it in the a variable*/
  while (a=='\n' || a=='\t' || a==' ')                           /*reading white space while we read white chars*/
  {
    a=getchar(); 
    if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9'))     /*the ony acceptable chars here are whites or numbers (for the height)*/
    {
      fprintf(stderr, "6.Input error\n");
      return 1;
    }
  }
  M=0;                                            /*initial value of height is 0*/
  b=a;                                           /*same as the above process for the width*/
  putchar(b);
  while (b!='\n' && b!='\t' && b!=' ')
  {
    M=(M*10)+(b-'0') ;
    b=getchar();
    if ((b<'0' || b>'9') && (b!='\n' && b!='\t' && b!=' '))
    {
      fprintf(stderr, "7.Input error\n");
      return 1;
    }
    putchar(b);
  }
  a=b;
  while (a=='\n' || a=='\t' || a==' ')
  {
    a=getchar(); 
    if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9'))   /*the ony acceptable chars here are whites or numbers (for the max)*/
    {
      fprintf(stderr, "8.Input error\n");
      return 1;
    }
  }



  


  if (num=='6')                                   /*if P6 input convert into P5 output*/
  {
    max=0;                                      /*inital value of max is 0*/
    b=a;                                       /*for sure the last char we read was a number,so we put it in the b variable*/
    putchar(b);                               /*put the ascii format of each max digit in the output*/
    while (b!='\n' && b!='\t' && b!=' ')     /*while no whites, we are reading the max*/  
    {
      max=(max*10)+(b-'0');                /*converting the ascii format digits in a whole decimal number*/
      if(max>255)                         /*highest max value can be 255*/
      {
        fprintf(stderr, "9.Input error\n");
        return 1;
      }
      b=getchar();
      if ((b<'0' || b>'9') && (b!='\n' && b!='\t' && b!=' '))    /*the ony acceptable chars here are numbers or whites (for the next white space)*/ 
      {
        fprintf(stderr, "10.Input error\n");
        return 1;
      }
      putchar(b);
    }
    a=b;                               /*only one white because we are in the P6 format*/
    ch=getchar();                     /*raeding the first pixel's RED value and one getchar is enough because RGBs are in binary*/
    if (ch<0 || ch>max)              /*RGB values need to be in that range*/
    {
      fprintf(stderr, "11.Input error\n");
      return 1;
    }
    pixels2=0;                       /*how many pixels' RGB  have i read until now*/
    while(ch!=EOF)                  /*keep reading RGB until the end of file*/
    {
      pixels2=pixels2+1;
      if (pixels2>(N*M))          /*you shouldnt read more pixels' RGB-values  than N*M */
      {
        fprintf(stderr, "12.Input error\n");
        return 1;
      }
      R=ch;                       
      G=getchar();
      if (G<0 || G>max)
      {
        fprintf(stderr, "13.Input error\n");
        return 1;
      }
      B=getchar();
      if (B<0 || B>max )
      {
        fprintf(stderr, "14.Input error\n");
        return 1;
      } 
      grey= (299*R+587*G+114*B)/1000;        /*the equation you need to use to find the output file's-pixel's grey value*/
      putchar(grey);                        /*this puts in the output file the binary value of grey, putchar generally just 'puts' 1 byte*/
      ch=getchar();
      if ((ch<0 || ch>max) && (ch!=EOF))  /*after reading an RGB then you may also have an EOF */
      {
        fprintf(stderr, "15.Input error\n");
        return 1;
      }
    }
    if (pixels2<(N*M))    /*you shouldnt read less pixels' RGB-values  than N*M */
    {
      fprintf(stderr, "16.Input error\n");
      return 1;
    }
  } 







  


  if (num=='5')                                  /*if P5 convert to P4*/
  {
    max=0;                                     /*same process for the max as before*/
    b=a;
    while (b!='\n' && b!='\t' && b!=' ')
    {
      max=(max*10)+(b-'0');
      if(max>255)
      {
        fprintf(stderr, "17.Input error\n");
        return 1;
      }
      b=getchar();
      if ((b<'0' || b>'9') && (b!='\n' && b!='\t' && b!=' '))
      {
        fprintf(stderr, "18.Input error\n");
        return 1;
      }
    }
    a=b;                          /*only one white because we are in the P5 format*/ 
    pixels=0;                    /*how many pixels have i read in THIS row*/
    pixels2=0;                  /*how many pixels  have i read until now*/ 
    G=getchar();               /*read the GREY value of the first pixel*/
    pixels2=pixels2+1;        /*we have read one more pixel's GREY value in THIS row*/
    pixels=pixels+1;         /*we have read one more pixel's GREY value*/
    if (G<0 || G>max)       /*GREY values need to be in that range*/
    {
      fprintf(stderr, "19.Input error\n");
      return 1;
    }
    while(G!=EOF)                                       /*keep reading GREY until the end of file*/
    {
      teliko=0;                                       /*initial value of 8-pixels is 0 (or 00000000 in binary)*/
      for (i=1;i<=8;i++)                             /*read the GREY value of 8 pixels*/
      {
        br=0;                                     /*the for has not been broken yet*/
        if (G > (max+1)/2 )                      /*thats the equation we use to see if GREY is closer to white or to black */
        {
          blackwhite=0;                        /*now GREY is closer to white which is represented by 0*/
          teliko=(teliko<<1)|blackwhite;      /*we are now packing the 8 pixels into 1 'packet' using bitwise operations,                              
                                              basically the teliko will be moved once to the left and the 0 from white will be 'added' to the end*/
        }
        else
        {
          blackwhite=1;                     /*now GREY is closer to black which is represented by 0*/
          teliko=(teliko<<1)|blackwhite;   /*we are now packing the 8 pixels into 1 'packet' using bitwise operations,                              
                                           basically the teliko will be moved once to the left and the 1 from black will be 'added' to the end*/
        }
        if (N%8!=0)                             /*if the width is not a multiple of 8 and..*/
        {
          if (pixels==N)                      /*..if we are in the last pixel of THIS row */         
          {
            pixels=0;                       /*row is over*/
            for (j=1;j<=8-(N%8);j++)       /*this loop will happen until the last 'packet' of the row has also 8 pixels*/
            {
              teliko=(teliko<<1)|1;      /*add blacks to the end of the packet to make it an 8-pixel packet*/
            }
            br=1;                      /*this for loop has broken because the packet is complete and we dont need to read anymore pixels*/
            break;
          }
        }
        G=getchar();                      /*if br=0 that means that the width IS multiple of 8 OR that we are not yet in the last pixel of the row*/
        pixels2=pixels2+1;
        pixels=pixels+1;                    
        if ((G<0 || G>max) && (G!=EOF))
        {
          fprintf(stderr, "20.Input error\n");
          return 1;
        }
      }
      if (br==1)           /*if br=1 that means that the width IS NOT  multiple of 8 and that the last packet is now also an 8-pixels-packet*/
      {
        G=getchar();
        pixels2=pixels2+1;
        pixels=pixels+1;                   
        if ((G<0 || G>max) && (G!=EOF))
        {
          fprintf(stderr, "21.Input error\n");
          return 1;
        }
      }
      putchar(teliko);                   /*since all the info for 8 pixels is 1 byte it only needs 1 putchar for all 8*/
    }
    if ( (pixels2 -1) != (N*M) )        /*we are subtracting 1 because the EOF has also been counted in pixels2*/
    {
      fprintf(stderr, "22.Input error\n");
      return 1;
    }
  } 








  
  if (num=='3')                                  /*if P3 convert into P2*/
  {
    max=0;                                     /*same process for the max as before*/   
    b=a;
    putchar(b);
    while (b!='\n' && b!='\t' && b!=' ')
    {
      max=(max*10)+(b-'0');
      if(max>255)
      {
        fprintf(stderr, "23.Input error\n");
        return 1;
      }
      b=getchar();
      if ((b<'0' || b>'9') && (b!='\n' && b!='\t' && b!=' '))
      {
        fprintf(stderr, "24.Input error\n");
        return 1;
      }
      putchar(b);
    }
    a=b;   
    while (a=='\n' || a=='\t' || a==' ')                         /*reading whites until we get a nummber*/
    {
      a=getchar();
      if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9'))    /*those are the only acceptable chars here*/
      {
        fprintf(stderr, "25.Input error\n");
        return 1;
      }
    }
    b=a;                                            /*b is for sure a number*/
    pixels2=0;                                     /*how many pixels' value have we read*/
    while (b!=EOF)                                /*read pixels until the end of file*/
    {
      pixels2=pixels2+1;
      if (pixels2>(N*M))
      {
        fprintf(stderr, "26.Input error\n");
        return 1;
      }
      R=0;                                         
      while (b!='\n' && b!='\t' && b!=' ')              /*reading the ascii-format digits of RED until we get a white*/
      {
        R=(R*10)+(b-'0');                              /*converting the ascii format digits into 1 whole decimal number*/
        if(R>max)                                     /*RED can not be higher than the max value we read before*/
        {
          fprintf(stderr, "27.Input error\n");
          return 1;
        }
        b=getchar();
        if ((b!='\n'&& b!='\t' && b!=' ') && (b<'0' || b>'9'))     /*those are the only acceptable chars here*/
        {
          fprintf(stderr, "28.Input error\n");
          return 1;
        }
      } 
      a=b;                                                   /*the last char we read was for sure a white so we put it in the a variable*/
      while (a=='\n' || a=='\t' || a==' ')                   /*reading whites until we get a number*/
      {
        a=getchar(); 
        if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9'))
        {
          fprintf(stderr, "29.Input error\n");
          return 1;
        }
      }
      G=0;                                                        /*same for GREEN*/
      b=a;                                                       /*the last char we read was for sure a number so we put it in the b variable*/
      while (b!='\n' && b!='\t' && b!=' ')
      {
        G=(G*10)+(b-'0');
        if(G>max)
        {
          fprintf(stderr, "30.Input error\n");
          return 1;
        }
        b=getchar();
        if ((b!='\n'&& b!='\t' && b!=' ') && (b<'0' || b>'9'))
        {
          fprintf(stderr, "31.Input error\n");
          return 1;
        }
      }
      a=b;
      while (a=='\n' || a=='\t' || a==' ')
      {
        a=getchar(); 
        if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9'))
        {
          fprintf(stderr, "32.Input error\n");
          return 1;
        }
      } 
      B=0;                                                      /*same for BLUE*/
      b=a;
      while (b!='\n' && b!='\t' && b!=' ' && b!=EOF)
      {
        B=(B*10)+(b-'0');
        if(B>max)
        {
          fprintf(stderr, "33.Input error\n");
          return 1;
        }
        b=getchar();
        if ((b!='\n'&& b!='\t' && b!=' ') && (b<'0' || b>'9'))
        {
          fprintf(stderr, "34.Input error\n");
          return 1;
        }
      }
      a=b;
      while (a=='\n' || a=='\t' || a==' ')
      {
        a=getchar(); 
        if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9') && (a!=EOF))
        {
          fprintf(stderr, "35.Input error\n");
          return 1;
        }
      }
      b=a;                                            /*the last char we read was for sure a number or EOF so we put it in the b variable*/
      grey= (299*R+587*G+114*B)/1000;                /*thats the equation we use to find the grey value*/
      printf("%d\n",grey);                          /*in this way we put the ascii-format of grey's digits in the output file*/
    }
    if (pixels2<(N*M))
    {
      fprintf(stderr, "36.Input error\n");
      return 1;
    }
  }









  
  if (num=='2')                                    /*if P2 convert into P1*/
  {
    max=0;                                        /*same process for the max as before*/
    b=a;                                         /*P1 doesnt need the max value so we dont put it in it with a putchar*/
    while (b!='\n' && b!='\t' && b!=' ')
    {
      max=(max*10)+(b-'0');
      if(max>255)
      {
        fprintf(stderr, "37.Input error\n");
        return 1;
      }
      b=getchar();
      if ((b<'0' || b>'9') && (b!='\n' && b!='\t' && b!=' '))
      {
        fprintf(stderr, "38.Input error\n");
        return 1;
      }
    }
    a=b;                              
    while (a=='\n' || a=='\t' || a==' ')
    {
      a=getchar(); 
      if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9'))
      {
        fprintf(stderr, "39.Input error\n");
        return 1;
      }
    }
    b=a; 
    pixels2=0;                                                /*same as before*/
    while (b!=EOF)     
    {
      pixels2=pixels2+1;
      if (pixels2>(N*M))
      {
        fprintf(stderr, "40.Input error\n");
        return 1;
      }
      G=0;                                                /*same as before but now we only have one value,the GREY value*/
      while (b!='\n' && b!='\t' && b!=' ' && b!=EOF)
      {
        G=(G*10)+(b-'0');
        if(G>max)
        {
          fprintf(stderr, "41.Input error\n");
          return 1;
        }
        b=getchar();  
        if ((b!='\n'&& b!='\t' && b!=' ') && (b<'0' || b>'9'))
        {
          fprintf(stderr, "42.Input error\n");
          return 1;
        }
      }
      a=b;
      while (a=='\n' || a=='\t' || a==' ')
      {
        a=getchar(); 
        if ((a!='\n'&& a!='\t' && a!=' ') && (a<'0' ||a>'9') && (a!=EOF))
        {
          fprintf(stderr, "43.Input error\n");
          return 1;
        }
      }
      b=a; 
      if (G > (max+1)/2 )                                /*thats the equation we use to see if the correspoinding pixel in P1 will be black or white*/
      {
        blackwhite=0;                                   /*0 is white*/
      }
      else
      {
        blackwhite=1;                                 /*1 is black*/
      }
      putchar(blackwhite+'0');                       /*in order to put the ascii char of the 0 or 1 we need to add '0' */
    }
    if (pixels2<(N*M))
    {
      fprintf(stderr, "44.Input error\n");
      return 1;
    }
  }
}
