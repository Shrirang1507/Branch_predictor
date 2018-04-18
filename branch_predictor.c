#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

    //int *ptr;
    int number_of_branches = 0;
    int number_of_mispredictions = 0;
    int number_of_predictions = 0;
    int number_of_hybrid_branches = 0;
    int number_of_hybrid_mispredictions = 0;
    int number_of_hybrid_predictions = 0;
    int gbhr = 0;
//    int qwerty = 0;

int bimodal(int m2, int btb_size, int btb_assoc, int hex, char* action, int* ptr, char* predict)
{
    //int m;
    //int *ptr;
    int a,b,i;
//    char predict[2];

    number_of_branches++;

    a = ((1<<(m2+2)) - 1);
//    printf("%d\n",a);
    b = (hex&a)>>2;
//    printf("%d\n", b);
//    printf("%d\n",ptr[b]);

    if(ptr[b]>=2)
        strcpy(predict,"t");
    else if(ptr[b]<2)
        strcpy(predict,"n");

    if(!strcmp(predict,action))
        number_of_predictions++;
//        printf("%d\n",number_of_predictions);
    else
        number_of_mispredictions++;

    if(!strcmp(action,"t"))
    {
        if(ptr[b] == 3)
            ptr[b] = 3;
        else
            ptr[b]++;
    }
    else if(!strcmp(action,"n"))
    {
        if(ptr[b] == 0)
            ptr[b] = 0;
        else
        ptr[b]--;
    }
    return(0);
}

int bimodal_h(int m2, int btb_size, int btb_assoc, int hex, char* action, int* ptr, char* predict)
{
    //int m;
    //int *ptr;
    int a,b,i;
//    char predict[2];

    number_of_branches++;

    a = ((1<<(m2+2)) - 1);
//    printf("%d\n",a);
    b = (hex&a)>>2;
//    printf("%d\n", b);
//    printf("%d\n",ptr[b]);

    if(ptr[b]>=2)
        strcpy(predict,"t");
    else if(ptr[b]<2)
        strcpy(predict,"n");

       return(0);
}

int bimodal_u (int m2, int btb_size, int btb_assoc, int hex, char* action, int* ptr, char* predict)
{
    int a,b,i;

    a = ((1<<(m2+2)) - 1);
//    printf("%d\n",a);
    b = (hex&a)>>2;

    if(!strcmp(action,"t"))
        {
        if(ptr[b] == 3)
            ptr[b] = 3;
        else
            ptr[b]++;
        }
        else if(!strcmp(action,"n"))
        {
            if(ptr[b] == 0)
            ptr[b] = 0;
            else
            ptr[b]--;
        }
    return(0);
}

int gshare(int m1, int n, int btb_size, int btb_assoc, int hex, char* action, int* ptr1, char* predict1)
{
    int a,b,c,d,e,f,g;
    //char predict[2];

    number_of_branches++;
//printf("\n//////////%d\n", qwerty);

//    g = ((1<<(n)) - 1);
//    gbhr = (gbhr&g);
    a = ((1<<(m1+2)) - 1);
    b = (hex&a)>>2;
    e = ((1<<(m1-n)) - 1);
    f = (b&e);
//printf("%d\n",f);
    c = ((b>>(m1-n)) ^ (gbhr));
    d = ((c<<(m1-n)) | f);
//printf("%d\n",d);
    if(ptr1[d]>=2)
        strcpy(predict1,"t");
    else if(ptr1[d]<2)
        strcpy(predict1,"n");

    if(!strcmp(predict1,action))
        number_of_predictions++;
    else
        number_of_mispredictions++;

    if(!strcmp(action,"t"))
    {
        if(ptr1[d] == 3)
            ptr1[d] = 3;
        else
            ptr1[d]++;
        gbhr = ((gbhr>>1) | (1<<(n-1)));
//        printf("%d\n", ptr[d]);
    }
    else if(!strcmp(action,"n"))
    {
        if(ptr1[d] == 0)
            ptr1[d] = 0;
        else
        ptr1[d]--;
        gbhr = ((gbhr>>1) & ((1<<(n)) - 1));
    }
//qwerty++;

    return(0);
}

int gshare_h(int m1, int n, int btb_size, int btb_assoc, int hex, char* action, int* ptr1, char* predict1)
{
    int a,b,c,d,e,f,g;
    //char predict[2];

    number_of_branches++;
//printf("\n//////////%d\n", qwerty);

//    g = ((1<<(n)) - 1);
//    gbhr = (gbhr&g);
    a = ((1<<(m1+2)) - 1);
    b = (hex&a)>>2;
    e = ((1<<(m1-n)) - 1);
    f = (b&e);
//printf("%d\n",f);
    c = ((b>>(m1-n)) ^ (gbhr));
    d = ((c<<(m1-n)) | f);
//printf("%d\n",d);
    if(ptr1[d]>=2)
        strcpy(predict1,"t");
    else if(ptr1[d]<2)
        strcpy(predict1,"n");

    return(0);
}

int gshare_u(int m1, int n, int btb_size, int btb_assoc, int hex, char* action, int* ptr1, char* predict1)
{
    int a,b,c,d,e,f,g;
    //char predict[2];

    number_of_branches++;
//printf("\n//////////%d\n", qwerty);

//    g = ((1<<(n)) - 1);
//    gbhr = (gbhr&g);
    a = ((1<<(m1+2)) - 1);
    b = (hex&a)>>2;
    e = ((1<<(m1-n)) - 1);
    f = (b&e);
//printf("%d\n",f);
    c = ((b>>(m1-n)) ^ (gbhr));
    d = ((c<<(m1-n)) | f);

     if(!strcmp(action,"t"))
    {
        if(ptr1[d] == 3)
            ptr1[d] = 3;
        else
            ptr1[d]++;
        gbhr = ((gbhr>>1) | (1<<(n-1)));
//        printf("%d\n", ptr[d]);
    }
    else if(!strcmp(action,"n"))
    {
        if(ptr1[d] == 0)
            ptr1[d] = 0;
        else
        ptr1[d]--;
        gbhr = ((gbhr>>1) & ((1<<(n)) - 1));
    }
    return(0);
}

int hybrid(int k, int m1, int n, int m2, int btb_size, int btb_assoc, int hex, char* action, int* ptr, int* ptr1, int* chooser, char* predict, char* predict1, char* predict_h, char* predict_h1)
{
    int a,b,z,y,x,w;
    char p[2];
//printf("aala");
    z = ((1<<(k+2)) - 1);
    y = (hex&z)>>2;

        a = bimodal_h(m2, btb_size, btb_assoc, hex, action, ptr, predict_h);
        b = gshare_h(m1, n, btb_size, btb_assoc, hex, action, ptr1, predict_h1);

    number_of_hybrid_branches++;
//printf("%s %s %s\t",predict_h, predict_h1, action);

    if(chooser[y]>=2)
    {
        strcpy(p,predict_h1);
        if(!strcmp(p,action))
            number_of_hybrid_predictions++;
        else
            number_of_hybrid_mispredictions++;

         b = gshare_u(m1, n, btb_size, btb_assoc, hex, action, ptr1, predict_h1);
    }
    else if(chooser[y]<2)
    {
        strcpy(p,predict_h);
        if(!strcmp(p,action))
            number_of_hybrid_predictions++;
        else
            number_of_hybrid_mispredictions++;

        a = bimodal_u(m2, btb_size, btb_assoc, hex, action, ptr, predict_h);

        if(!strcmp(action,"t"))
            gbhr = ((gbhr>>1) | (1<<(n-1)));
        else if(!strcmp(action,"n"))
            gbhr = ((gbhr>>1) & ((1<<(n)) - 1));
    }

    if(!strcmp(predict_h1,action) && !strcmp(predict_h,action))
    {
        chooser[y] = chooser[y];
    }
    else if(!strcmp(predict_h1,action))
    {
        if(chooser[y] == 3)
            chooser[y] = 3;
        else
            chooser[y]++;

//printf("%d %d increase gshare\n",y,chooser[y]);
    }
    else if(!strcmp(predict_h,action))
    {
        if(chooser[y] == 0)
            chooser[y] = 0;
        else
            chooser[y]--;

//printf("%d %d increase bimodal\n",y,chooser[y]);
    }

    return(0);
}

int main(int argc, char *argv[])
{
    int m2,m1,n,k;
    int btb_size;
    int btb_assoc;
    char trace_file[30], mode[30];

    int *ptr;
    int *chooser;
    int *ptr1;
    int m,z,mn;
    int hex;
    char action[2];
    float misprediction_rate;
    int a, i;
    char predict[2], predict1[2];
    char predict_h[2], predict_h1[2];

    FILE *fp;

    if(!strcmp(argv[1], "bimodal"))
    {
        strcpy(mode, argv[1]);
//        printf("%s\n", mode);
        m2 = atoi(argv[2]);
//        printf("%d\n", m2);
        btb_size = atoi(argv[3]);
//        printf("%d\n", btb_size);
        btb_assoc = atoi(argv[4]);
//        printf("%d\n",btb_assoc);
        strcpy(trace_file, argv[5]);
//        printf("%s\n", trace_file);

         m = pow(2,m2);
         ptr = (int *) malloc (m * sizeof (int));

         for(i=0;i<m;i++)
        {
        ptr[i] = 2;
        }

    }
    else if(!strcmp(argv[1],"gshare"))
    {
        strcpy(mode, argv[1]);
//printf("%s\n", mode);
        m1 = atoi(argv[2]);
        n = atoi(argv[3]);
        btb_size = atoi(argv[4]);
//printf("%d\n", btb_size);
        btb_assoc = atoi(argv[5]);
//printf("%d\n",btb_assoc);
        strcpy(trace_file, argv[6]);
//printf("%s\n", trace_file);

        mn = pow(2,m1);
         ptr1 = (int *) malloc (mn * sizeof (int));

        for(i=0;i<mn;i++)
        {
        ptr1[i] = 2;
        }
    }
    else if(!strcmp(argv[1],"hybrid"))
    {
//printf("Ohho\n");
        strcpy(mode, argv[1]);
        k = atoi(argv[2]);
        m1 = atoi(argv[3]);
        n = atoi(argv[4]);
        m2 = atoi(argv[5]);
        btb_size = atoi(argv[6]);
        btb_assoc = atoi(argv[7]);
        strcpy(trace_file, argv[8]);
//printf("%s\n",trace_file);

        m = pow(2,m2);
         ptr = (int *) malloc (m * sizeof (int));

        mn = pow(2,m1);
         ptr1 = (int *) malloc (mn * sizeof (int));

        z = pow(2,k);
         chooser = (int *) malloc (z * sizeof(int));

        for(i=0;i<z;i++)
        {
        chooser[i] = 1;
        }

        for(i=0;i<mn;i++)
        {
        ptr1[i] = 2;
        }

        for(i=0;i<m;i++)
        {
        ptr[i] = 2;
        }
//printf("chalu tar aahe\n");
    }


//    m = pow(2,m2);
////    printf("%d\n", m);
//    ptr = (int *) malloc (m * sizeof (int));
////    printf("Malloc hotay\n");

//    for(i=0;i<m;i++)
//    {
//        ptr[i] = 2;
//    }

//     for(i=0;i<m;i++)
//    {
//        printf("%d\n", ptr[i]);
//    }


    fp = fopen(trace_file, "r");

    while(fscanf(fp, "%x %s", &hex, action) != EOF)
    {
        //printf("Hooka Chaka\n");
        //fscanf(fp, "%x %s", &hex, action);
        //printf("%x %s\n", hex, action);
        if (!strcmp(mode,"bimodal"))
            a = bimodal(m2, btb_size, btb_assoc, hex, action, ptr, predict);
        else if(!strcmp(mode,"gshare"))
            a = gshare(m1, n, btb_size, btb_assoc, hex, action, ptr1, predict1);
        else if(!strcmp(mode,"hybrid"))
            a = hybrid(k, m1, n, m2, btb_size, btb_assoc, hex, action, ptr, ptr1, chooser, predict, predict1, predict_h, predict_h1);
    }
    fclose(fp);

    if(!strcmp(argv[1],"hybrid"))
    {
        misprediction_rate = ((float)(number_of_hybrid_mispredictions)/(number_of_hybrid_branches)*100);
        printf("COMMAND\n");
        printf("./sim hybrid %d %d %d %d %d %d %s\n",k,m1,n,m2,btb_size,btb_assoc,trace_file);
        printf("OUTPUT\n");
        printf("number of predictions:\t%d\n", number_of_hybrid_branches);
        printf("number of mispredictions:\t%d\n", number_of_hybrid_mispredictions);
        printf("misprediction rate:\t%.2f%%\n", misprediction_rate);
        printf("FINAL CHOOSER CONTENTS\n");
        for(i=0;i<z;i++)
        {
            printf("%d\t%d\n",i,chooser[i]);
        }
        printf("FINAL GSHARE CONTENTS\n");
        for (i=0;i<mn;i++)
        {
            printf("%d\t%d\n",i,ptr1[i]);
        }
        printf("FINAL BIMODAL CONTENTS\n");
        for (i=0;i<m;i++)
        {
            printf("%d\t%d\n",i,ptr[i]);
        }

    }
    else if(!strcmp(argv[1],"bimodal"))
    {
        misprediction_rate = ((float)(number_of_mispredictions)/(number_of_branches)*100);
        printf("COMMAND\n");
        printf("./sim bimodal %d %d %d %s\n",m2,btb_size,btb_assoc,trace_file);
        printf("OUTPUT\n");
        printf("number of predictions:\t%d\n", number_of_branches);
        printf("number of mispredictions:\t%d\n", number_of_mispredictions);
        printf("misprediction rate:\t%.2f%%\n", misprediction_rate);
        printf("FINAL BIMODAL CONTENTS\n");
        for (i=0;i<m;i++)
        {
            printf("%d\t%d\n",i,ptr[i]);
        }
    }
    else if(!strcmp(argv[1],"gshare"))
    {
        misprediction_rate = ((float)(number_of_mispredictions)/(number_of_branches)*100);
        printf("COMMAND\n");
        printf("./sim gshare %d %d %d %d %s\n",m1,n,btb_size,btb_assoc,trace_file);
        printf("OUTPUT\n");
        printf("number of predictions:\t%d\n", number_of_branches);
        printf("number of mispredictions:\t%d\n", number_of_mispredictions);
        printf("misprediction rate:\t%.2f%%\n", misprediction_rate);
        printf("FINAL GSHARE CONTENTS\n");
        for (i=0;i<mn;i++)
        {
            printf("%d\t%d\n",i,ptr1[i]);
        }
    }

    return(0);
}
