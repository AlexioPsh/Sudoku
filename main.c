#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int x, y, grid[9][9],N, Ny, i=0,  imax=0;
int tabuleiro() {
    printf("   | 1  2  3  | 4  5  6  | 7  8  9  | x");
    printf("\n-------------------------------------");
    for(y=0;y<9;y++){
        printf("\n %d ", y + 1);
        printf("| ");
        for(x=0;x<9;x++){
            printf("%d  ", grid[x][y]);
            if((x+1)%3==0){
                printf("| ");
            }
        }
        if((y+1)%3==0){
            printf("\n-------------------------------------");
        }
    }
    printf("\n y");
}
int validacaolinha(int val){
        // validação na linha(salta a posição do X no primeiro if dentro do while)
        N=0;
        while(N<9){
            if (grid[N][y]==val){
                return -1;
                i=1;
            }
            else{
                N++;
            }
        }
        return 0;
        i=0;
}
int validacaocoluna(int val){

        N=0;
        // validação na coluna(salta a posição do Y no primeiro if dentro do while)
        while(N<9){
            if (grid[x][N]==val){
               return -1;
               i=1;
            }
            else{
                N++;
            }
        }
        return 0;
        i=0;

}
int validacaomatriz3x3(int val) {
        //validação na matriz 3x3
    //no int main usei a expressão x=x-1; e y=y-1; daí verificar se os valores estão entre 0 e 2 em vez de 1 e 3
    if (y>=0 && y<=2){
            if(x>=0 && x<=2){
                i=0;
                imax=2;
            }
            if(x>=3 && x<=5){
                i=3;
                imax=5;
            }
            if(x>=6 && x<=8){
                i=6;
                imax=8;
            }
            for(i=i;i<=imax+1;i++){
                if(i%3==0 && Ny<2 && i!=0 && x>=0 && x<=2){
                    Ny=Ny+1;
                    i=i-3;
                }
                if(i%3==0 && Ny<2 && i!=3 && x>=3 && x<=5){
                    Ny=Ny+1;
                    i=i-3;
                }
                if(i%3==0 && Ny<2 && i!=6 && x>=6 && x<=8){
                    Ny=Ny+1;
                    i=i-3;
                }

                if (grid[i][Ny]==val){
                        return 1;
                }
        }
    }
    if (y>=3 && y<=5){
            if(x>=0 && x<=2){
                i=0;
                imax=2;
            }
            if(x>=3 && x<=5){
                i=3;
                imax=5;
            }
            if(x>=6 && x<=8){
                i=6;
                imax=8;
            }
            Ny=3;
            for(i=i;i<=imax+1;i++){
                if(i%3==0 && Ny<5 && i!=0 && x>=0 && x<=2){
                    Ny=Ny+1;
                    i=i-3;
                }
                if(i%3==0 && Ny<5 && i!=3 && x>=3 && x<=5){
                    Ny=Ny+1;
                    i=i-3;
                }
                if(i%3==0 && Ny<5 && i!=6 && x>=6 && x<=8){
                    Ny=Ny+1;
                    i=i-3;
                }

                if (grid[i][Ny]==val){
                        return 1;
                }
        }
    }
    if (y>=6 && y<=8){
            if(x>=0 && x<=2){
                i=0;
                imax=2;
            }
            if(x>=3 && x<=5){
                i=3;
                imax=5;
            }
            if(x>=6 && x<=8){
                i=6;
                imax=8;
            }
            Ny=6;
            for(i=i;i<=imax+1;i++){
                if(i%3==0 && Ny<8 && i!=0 && x>=0 && x<=2){
                    Ny=Ny+1;
                    i=i-3;
                }
                if(i%3==0 && Ny<8 && i!=3 && x>=3 && x<=5){
                    Ny=Ny+1;
                    i=i-3;
                }
                if(i%3==0 && Ny<8 && i!=6 && x>=6 && x<=8){
                    Ny=Ny+1;
                    i=i-3;
                }

                if (grid[i][Ny]==val){
                        return 1;
                }
        }
    }
    Ny=0;
    return 0;
}
int main()
{
    int val;
    do{

        setlocale(LC_ALL, "Portuguese");
        tabuleiro();

        printf("\nEscolha a posição em que quer jogar\nx: ");
        scanf("%d", &x);
        while(x<0 || x>9){
            printf("O x está entre 1 e 9: ");
            scanf("%d", &x);
        }
        x=x-1;
        printf("y: ");
        scanf("%d", &y);
        while(y<0 || y>9){
            printf("O y está entre 1 e 9: ");
            scanf("%d", &y);
        }
        y=y-1;


        printf("Número dessa posição: ");
        scanf("%d", &val);
        while(val<=0||val>=10){
            printf("O número tem de estar entre 0 e 9: ");
            scanf("%d", &val);
        }
        while(validacaolinha(val)!=0 || validacaocoluna(val)!=0 || validacaomatriz3x3(val)!=0){
            if(validacaolinha(val)!=0){
                printf("Valor igual encontrado na posição x=%d y=%d", N+1, y+1);
                printf("\nTente outra vez: ");
                scanf("%d", &val);
                while(val<=0||val>=10){
                    printf("O número tem de estar entre 0 e 9: ");
                    scanf("%d", &val);
                }
                N=0;
                Ny=0;
            }
            if(validacaocoluna(val)!=0){
                printf("Valor igual encontrado na posição x=%d y=%d", x+1, N+1);
                printf("\nTente outra vez: ");
                scanf("%d", &val);
                while(val<=0||val>=10){
                    printf("O número tem de estar entre 0 e 9: ");
                    scanf("%d", &val);
                }
                N=0;
                Ny=0;
            }
            if(validacaomatriz3x3(val)!=0){
                printf("Valor igual encontrado na posição x=%d y=%d", i+1, Ny+1);
                printf("\nTente outra vez: ");
                scanf("%d", &val);
                while(val<=0||val>=10){
                    printf("O número tem de estar entre 0 e 9: ");
                    scanf("%d", &val);
                }
                N=0;
                Ny=0;
            }
        }

        system("cls");
        grid[x][y]=val;
    }
    while(1);
}
