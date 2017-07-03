//
//  main.c
//  GPSLatitude
//
//  Created by 20161104595 on 17/7/3.
//  Copyright © 2017年 20161104595. All rights reserved.
//

#include <stdio.h>
#include<string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
        FILE *fp1;
        FILE *fp2;
        char str1[70],str2[70];
        char time[10],latitude[10],longitute[10],date[10],high[10],rate[10],course[10];
        int i;
        fp1=fopen("//Users//a20161104595//Desktop//gps1//GPSLatitude//GPS170510.log","r+");
        fp2=fopen("//Users//a20161104595//Desktop//gps1//GPSLatitude//test.csv","w+");
        if(fp1 == NULL)
        {
            printf("要打开的文件不存在");
            return 0;
        }
        
        else
        {
            printf("时间,纬度,经度,日期,海拔,地面速率,地面航向\n");
            fprintf(fp2,"时间,纬度,经度,日期,海拔,地面速率,地面航向\n");
            while(fscanf(fp1,"%s%s",str1,str2)!=EOF)
            {
                for(i=0;i<6;i++)
                {
                    time[i]=str1[i+7];
                }
                time[6]='\0';
                
                for(i=0;i<8;i++)
                {
                    latitude[i]=str1[i+16];
                }
                latitude[8]='\0';
                
                for(i=0;i<9;i++)
                {
                    longitute[i]=str1[i+27];
                }
                longitute[9]='\0';
                
                for(i=0;i<6;i++)
                {
                    date[i]=str1[i+51];
                }
                date[6]='\0';
                
                for(i=0;i<4;i++)
                {
                    high[i]=str2[i+43];
                }
                high[4]='\0';
                
                for(i=0;i<5;i++)
                {
                    rate[i]=str1[i+39];
                }
                rate[5]='\0';
                
                for(i=0;i<5;i++)
                {
                    course[i]=str1[i+45];
                }
                course[5]='\0';
                
                printf("'%s,%s,%s,%s,%s,%s,%s\n",time,latitude,longitute,date,high,rate,course);
                fprintf(fp2,"'%s,%s,%s,%s,%s,%s,%s\n",time,latitude,longitute,date,high,rate,course);
            }
            fclose(fp1);
        }
        return 0;

}
