#include <stdio.h>
#include <string.h>

// function month
int month(int year, int firstday, int m1daysnum, int m2daysnum, int m3daysnum) {
 
int z, a, b, c, d, i, j, k, day, m1som, m1eom, m2som, m2eom, m3som, m3eom;
int m1days[m1daysnum], m2days[m2daysnum], m3days[m3daysnum];
i=0; j=0; k=0;
m1som = firstday;

// initialize month arrays
for (a=1; a<=m1daysnum; a=a+1) {
 m1days[a-1] = a;
}

for(b=1; b<=m2daysnum; b=b+1) {
  m2days[b-1] = b;
}

for(c=1; c<=m3daysnum; c=c+1) {
 m3days[c-1] = c;
}

printf("\nSu Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa\n");

int m1sp = space(firstday);

// first week
 // first month
   // first day
for(z=1; z<m1sp; z=z+1) {
  printf(" ");
}
printf("%d", m1days[i]);
i++;
   // rest of week
for(day=m1som+1; day<=7; day=day+1) {
  printf("%3d", m1days[i]);
  i=i+1;
}
m1eom = eom(m1som,m1daysnum);
 
 // second month
   // first day
m2som = m1eom + 1;
int m2sp = space(m2som);
for(z=1; z<m2sp+2; z=z+1) {
  printf(" ");
}
printf("%d", m2days[j]);
j++;
   // rest of week
for(day=m2som+1; day<=7; day=day+1) {
  printf("%3d", m2days[j]);
  j=j+1;
}
m2eom = eom(m2som, m2daysnum);

 // third month
   // first day
m3som = m2eom + 1;
int m3sp = space(m3som);
for(z=1; z<m3sp+2; z=z+1) {
  printf(" ");
}
printf("%d", m3days[k]);
k++;
   // rest of week
for(day=m3som+1; day<=7; day=day+1) {
  printf("%3d", m3days[k]);
  k=k+1;
}
printf("\n");

// 2nd week to 4th week m1
 // first month
   // first day
m1sp = 2; m1som = 0;
int test = 1;
while(i != (m1daysnum-1) && test != 4) {
printf("%2d", m1days[i]);
i++;
   // rest of week
for(day=m1som+1; day<7; day=day+1) {
 if(i != (m1daysnum-1)) { 
  printf("%3d", m1days[i]);
  i=i+1; }
}
     
 // second month
   // first day
if(j != (m2daysnum-1)) {
m2sp = 1; m2som = 0;
for(z=1; z<m2sp+2; z=z+1) {
  printf(" ");
}
printf("%2d", m2days[j]);
j++;
   // rest of week
for(day=m2som+1; day<7; day=day+1) {
  printf("%3d", m2days[j]);
  j=j+1; 
}

 // third month
   // first day
m3sp = 1; m3som = 0;
for(z=1; z<m3sp+2; z=z+1) {
  printf(" ");
}
printf("%2d", m3days[k]);
k++;
   // rest of week
for(day=m3som+1; day<7; day=day+1) {
  printf("%3d", m3days[k]);
  k=k+1;
}
printf("\n");
} // end of first if
test = test+1;
} // end of  while

// last week of m1
int endday = 1;
int test2 = 1;
 // finish m1
  // print day1
  printf("%d", m1days[i]);
  i++;
  // print rest of week
  for(day=m1som+1; day<7; day=day+1) {
   if(i != m1daysnum) { 
    printf("%3d", m1days[i]);
    i=i+1;
    endday = endday+1; }
  }
int dayf = 1;
// when m1 is done, finish m2
  while(j <= (m2daysnum-1) && test2 != 2) {
  m2som = 0;
  // print day1
  for(z=1; z<(23-space(endday)); z=z+1) {
    printf(" ");
  }
  printf("%2d", m2days[j]);
  j++;
  // print rest of days
  for(day=m2som+1; day<7; day=day+1) {
  if(j != (m2daysnum)) {
    printf("%3d", m2days[j]);
    j=j+1;
    dayf = dayf+1; }
  }
  test2 = 2;
  } // end of second while

int test3 = 1;
int daym = 1;
int m3end = 1;              
 // when m2 is over
     // first day
     if(k != (m3daysnum-1) && test3 != 2) {
     m3sp = 2; m3som = 0;
     for(z=1; z<(47-(space(dayf)+24)); z=z+1) {
      printf(" ");
    }
    printf("%2d", m3days[k]);
    k++;
    // rest of week
    for(day=m3som+1; day<7; day=day+1) {
     if(k != (m3daysnum)) {
      printf("%3d", m3days[k]);
      k=k+1;
      daym = daym+1;
      m3end = m3end+1; }
    }
  
  // check if we need another week
    if(daym >= 6 || (endday >= 6 && i != m1daysnum) || (dayf >= 6 && j != m2daysnum)) {
    printf("\n"); }
    test3 = 2;
    } // end of third if
     int check1 = 0;
     // print last weeks
      // m1 last week if needed
     if(i != m1daysnum) {
     if(endday >= 6) {
      printf("%2d", m1days[i]);
      i++; }
     // print last days in last week
     endday = 1;                             
     for(day=1; day<7; day=day+1) {
     if(i != m1daysnum) {
      printf("%3d", m1days[i]);
      i=i+1;
      endday = endday+1;}                         
      }
     check1 = 1;
     } // end of m1 last week

     int check2 = 0;
    // m2 last week if needed
     if(j != m2daysnum) {
     if(dayf >= 6) {
      if(i>=m1daysnum) {
       for(z=1;z<23;z=z+1) {
       printf(" "); }
     } else {
     for(z=1; z<(23-space(endday)); z=z+1) {  
       printf(" ");
      }
     }
      printf("%2d", m2days[j]);
      j++; }
     dayf = 1;
     // print last days in last week
     for(day=1; day<7; day=day+1) {
     if(j != m2daysnum) {
      printf("%3d", m2days[j]);
      j=j+1;
      dayf = dayf+1; }
      }
     check2 = 1;
     }// end of m2 last week if
    // m3 last week if needed
     if(k != m3daysnum) {
     m3end = 1;                          
     if(daym >= 6) {
      if(check2 == 1) {
    for(z=1; z<(47-(space(dayf)+24)); z=z+1) {
      printf(" ");
       }
      printf("%2d", m3days[k]);
      k++;
     } else {
      if(check1 == 1) {
       for(z=1; z<(45-(space(endday))); z=z+1) {
        printf(" ");
        }
        printf("%2d", m3days[k]);
        k++; }
      else {
      printf("%46d", m3days[k]);
      k++; }
      } 
    }
     // print last days in last week
     for(day=1; day<7; day=day+1) {
     if(k != m3daysnum) {
      printf("%3d", m3days[k]);
      k=k+1;
      m3end = m3end+1; }
       }
     } // end of m3 needed if
printf("\n");
return m3end;
} // end of month

// function eom
int eom (som, mdays) {
 // returns the number of day of week that is last in the month
int meom = (som-1) + (mdays % 7);
if(meom >= 7) {
 meom = meom-7;
}
return meom;
} // end of eom

// function space
int space(int firstday){
 // gives number of spaces needed to start a week at a given day
int startspace;

  if(firstday == 1) {
    startspace = 2;}
   else {
    if(firstday == 2) {
      startspace = 5;}
     else {
      if(firstday == 3) {
        startspace = 8;}
       else {
        if(firstday == 4) {
          startspace = 11;}
         else {
          if(firstday == 5) {
            startspace = 14;}
           else {
            if(firstday == 6) {
              startspace = 17;}
             else {
              startspace = 20;
             }
           }
         }
       }
     }
   }
 return startspace;
} // end of space


main()
{
int year, jan1, febdaysnum, m3end;

printf("What is the number of the year?\n");
scanf("%d", &year);
printf("\nWhat is the day of Jan. 1? (S-1 M-2 T-3 W-4 Th-5 F-6 Sa-7)\n");
scanf("%d", &jan1);

printf("\n%34d\n", year);
if(year % 4 == 0) {
 febdaysnum = 29;
}
 else {
 febdaysnum = 28;
}

printf("\n       January              February                March");
m3end = month(year, jan1, 31, febdaysnum, 31);
if(m3end==7) {
 m3end = 0; } 
printf("\n        April                  May                  June");
m3end = month(year, (m3end+1), 30, 31, 30);
if(m3end==7) {
 m3end = 0; } 
printf("\n        July                 August               September");
m3end = month(year, (m3end+1), 31, 31, 30);
if(m3end==7) {
 m3end = 0; } 
printf("\n       October              November              December");
month(year, (m3end+1), 31, 30, 31);
}
