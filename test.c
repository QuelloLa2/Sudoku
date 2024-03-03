#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SI 1
#define NO 0

void cambio_valori(char tabella[9][9])
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            tabella[y][x] = tabella[y][x] + '0';
        }
    }
}
void stampa_tabella(char tabella[9][9])
{
    for (int i = 0; i < 25; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int y = 0; y < 9; y++)
    {
        if (y % 3 == 0 && y != 0)
        {
            for (int i = 0; i < 25; i++)
            {
                if (i == 8 || i == 16)
                {
                    printf("+");
                }
                else if (i != 9 || i != 17)
                {
                    printf("-");
                }
            }
            printf("\n");
        }
        for (int x = 0; x < 9; x++)
        {
            if (x < 8)
            {
                if (x % 3 == 0)
                {
                    printf("| ");
                }
                if (tabella[y][x] >= 0 && tabella[y][x] <= 9)
                {
                    printf("%d ", tabella[y][x]);
                }
                else if (tabella[y][x] >= '0' && tabella[y][x] <= '9')
                {
                    printf("%d ", tabella[y][x] - 48);
                }
            }
            else if (x == 8)
            {
                if (tabella[y][x] >= 0 && tabella[y][x] <= 9)
                {
                    printf("%d ", tabella[y][x]);
                }
                else if (tabella[y][x] >= '0' && tabella[y][x] <= '9')
                {
                    printf("%d ", tabella[y][x] - 48);
                }
            }
        }
        printf("|\n");
    }
    for (int i = 0; i < 25; i++)
    {
        printf("-");
    }
    printf("\n");
}
int controllo(char tabella[9][9], int x, int y, int contenuto)
{
    for (int i = 0; i < 9; i++)
    {
        if (tabella[x][i] == contenuto)
        {
            return 0;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        if (tabella[i][y] == contenuto)
        {
            return 0;
        }
    }

    int startx = x - x % 3;
    int starty = y - y % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabella[startx + i][starty + j] == contenuto)
            {
                return 0;
            }
        }
    }

    return 1;
}
void mischia_tabella(int array[9])
{
    for (int i = 8; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
int riempi_tabella(char tabella[9][9], int x, int y)
{
    if (x == 8 && y == 9)
    {
        return 1;
    }

    if (y == 9)
    {
        x++;
        y = 0;
    }

    if (tabella[x][y] != 0)
    {
        return riempi_tabella(tabella, x, y + 1);
    }

    int contenuto_a[9];
    for (int i = 0; i < 9; i++)
    {
        contenuto_a[i] = i + 1;
    }

    mischia_tabella(contenuto_a);

    for (int i = 0; i < 9; i++)
    {
        int contenuto = contenuto_a[i];
        if (controllo(tabella, x, y, contenuto))
        {
            tabella[x][y] = contenuto;
            if (riempi_tabella(tabella, x, y + 1))
            {
                return 1;
            }
            tabella[x][y] = 0;
        }
    }

    return 0;
}
int controllo9x1(char tabella[9][9])
{
    int ymin = 0, xmin = 0, giusto, numero, tutto_giusto = 1;

    for (int y = ymin; y < 9; y++)
    {
        int numeri_mancanti[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int x = xmin; x < 9; x++)
        {
            if (tabella[y][x] >= '1' && tabella[y][x] <= '9')
            {
                numero = tabella[y][x] - '0';
            }
            else if (tabella[y][x] >= 1 && tabella[y][x] <= 9)
            {
                numero = tabella[y][x];
            }
            for (int i = 0; i < 9; i++)
            {
                if (numeri_mancanti[i] == numero)
                {
                    numeri_mancanti[i] = 0;
                }
            }
        }
        giusto = 1;
        for (int i = 0; i < 9; i++)
        {
            if (numeri_mancanti[i] != 0)
            {
                giusto = 0;
            }
        }

        if (giusto == 0)
        {
            tutto_giusto = 0;
        }
    }

    return tutto_giusto;
}
int controllo1x9(char tabella[9][9])
{
    int giusto, numero, tutto_giusto = 1;
    for (int x = 0; x < 9; x++)
    {
        int numeri_mancanti[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (int y = 0; y < 9; y++)
        {
            if (tabella[y][x] >= '1' && tabella[y][x] <= '9')
            {
                numero = tabella[y][x] - '0';
            }
            else if (tabella[y][x] >= 1 && tabella[y][x] <= 9)
            {
                numero = tabella[y][x];
            }
            for (int i = 0; i < 9; i++)
            {
                if (numeri_mancanti[i] == numero)
                {
                    numeri_mancanti[i] = 0;
                }
            }
        }

        giusto = 1;
        for (int i = 0; i < 9; i++)
        {
            if (numeri_mancanti[i] != 0)
            {
                giusto = 0;
            }
        }

        if (giusto == 0)
        {
            tutto_giusto = 0;
        }
    }
    return tutto_giusto;
}
int controllo3x3(char tabella[9][9])
{
    int ymin = 0, xmin = 0, giusto, numero, tutto_giusto = 1;
    for (int quadrante = 0; quadrante < 9 && tutto_giusto; quadrante++)
    {
        int numeri_mancanti[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int y = ymin; y < ymin + 3; y++)
        {
            for (int x = xmin; x < xmin + 3; x++)
            {
                if (tabella[y][x] >= '1' && tabella[y][x] <= '9')
                {
                    numero = tabella[y][x] - '0';
                }
                else if (tabella[y][x] >= 1 && tabella[y][x] <= 9)
                {
                    numero = tabella[y][x];
                }
                for (int i = 0; i < 9; i++)
                {
                    if (numeri_mancanti[i] == numero)
                    {
                        numeri_mancanti[i] = 0;
                        break;
                    }
                }
            }
        }
        giusto = 1;
        for (int i = 0; i < 9; i++)
        {
            if (numeri_mancanti[i] != 0)
            {
                giusto = 0;
            }
        }
        if (giusto == 0)
        {
            tutto_giusto = 0;
        }

        xmin += 3;
        if (xmin >= 9)
        {
            xmin = 0;
            ymin += 3;
        }
    }
    if (tutto_giusto == SI)
    {
        return tutto_giusto;
    }
    else if (tutto_giusto == NO)
    {
        return tutto_giusto;
    }
}
void imposta_difficolta(int difficolta, char tabella[9][9])
{
    switch (difficolta)
    {
    case 1:
    {
        // facile: cpu=33 utente=48
        for (int i = 0; i < 48; i++)
        {
            int y = rand() % 9;
            int x = rand() % 9;
            if (tabella[y][x] != '0')
            {
                tabella[y][x] = '0';
            }
            else if (tabella[y][x] == '0')
            {
                i--;
            }
        }
    }
    break;
    case 2:
    {

        // medio: cpu=28 utente=53
        for (int i = 0; i < 53; i++)
        {
            int y = rand() % 9;
            int x = rand() % 9;
            if (tabella[y][x] != '0')
            {
                tabella[y][x] = '0';
            }
            else if (tabella[y][x] == '0')
            {
                i--;
            }
        }
    }
    break;
    case 3:
    {
        // difficile: cpu:23 utente=58
        for (int i = 0; i < 58; i++)
        {
            int y = rand() % 9;
            int x = rand() % 9;
            if (tabella[y][x] != '0')
            {
                tabella[y][x] = '0';
            }
            else if (tabella[y][x] == '0')
            {
                i--;
            }
        }
    }
    break;
    }
}
void salva_partita(char tabella[9][9])
{
    FILE *input;
    input = fopen("input.txt", "w");
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (tabella[y][x] >= '0' && tabella[y][x] <= '9')
            {
                fprintf(input, "%c", tabella[y][x] + 16);
            }
            else if (tabella[y][x] >= 0 && tabella[y][x] <= 9)
            {
                fprintf(input, "%c", tabella[y][x] + 96);
            }
        }
    }
    fclose(input);
}
int continua_partita(char tabella[9][9])
{
    FILE *input;
    input = fopen("input.txt", "r");
    if (input == NULL)
    {
        return 0;
    }
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            fscanf(input, "%c", &tabella[y][x]);
            if (tabella[y][x] >= 'A' && tabella[y][x] <= 'I' || tabella[y][x] == '@')
            {
                tabella[y][x] = tabella[y][x] - 16;
            }
            else if (tabella[y][x] >= 'a' && tabella[y][x] <= 'i')
            {
                tabella[y][x] = tabella[y][x] - 96;
            }
        }
    }
    fclose(input);
    return 1;
}
int main()
{
    int y, x, conferma, somma, vittoria, difficolta;
    char scelta[10] = {0}, numero;
    char tabella[9][9] = {0};
    srand(time(NULL));
    do
    {
        memset(scelta, 0, 10);
        conferma = SI;
        printf("-1 Nuova Partita (nuova)\n-2 Continua partita salvata(continua)\n");
        scanf("%s", scelta);
        if (strcmp(scelta, "nuova") == 0)
        {
            if (riempi_tabella(tabella, 0, 0))
            {
                cambio_valori(tabella);
                // tabella[4][4] = '0';
                printf("Sudoku generato:\n");
            }
            else
            {
                printf("Impossibile generare una tavola di Sudoku valida.\n");
                return 0;
            }
            do
            {
                memset(scelta, 0, 10);
                conferma = SI;
                printf("Imposta la difficolta: \n - Facile \n - Medio \n - Difficile\n");
                scanf("%s", scelta);
                if (strcmp(scelta, "facile") == 0)
                {
                    difficolta = 1;
                }
                else if (strcmp(scelta, "medio") == 0)
                {
                    difficolta = 2;
                }
                else if (strcmp(scelta, "difficile") == 0)
                {
                    difficolta = 3;
                }
                else if (strcmp(scelta, "facile") != 0 || strcmp(scelta, "medio") != 0 || strcmp(scelta, "difficile") != 0)
                {
                    conferma = NO;
                }
            } while (conferma == NO);
            imposta_difficolta(difficolta, tabella);
        }
        else if (strcmp(scelta, "continua") == 0)
        {
            conferma = continua_partita(tabella);
            if (conferma == NO)
            {
                printf("File non trovato");
                return 0;
            }
        }
        else if (strcmp(scelta, "continua") != 0 || strcmp(scelta, "nuova") != 0)
        {
            conferma = NO;
        }
    } while (conferma == NO);
    stampa_tabella(tabella);
    while (SI)
    {
        memset(scelta, 0, 10);
        do
        {
            printf(" - Inserire un numero in una cella (inserire)\n - Cancella un numero in una cella (cancella)\n - Per uscire dal gioco con salvatagglio (esci)\nScelta: ");
            scanf("%s", scelta);
            if (strcmp(scelta, "cancella") == 0 || strcmp(scelta, "inserire") == 0)
            {
                conferma = SI;
            }
            else if (strcmp(scelta, "esci") == 0)
            {
                salva_partita(tabella);
                printf("Partita salvata!\n Grazie per aver giocato\n A preso XD");
                return 0;
            }
            else if (strcmp(scelta, "cancella") != 0 || strcmp(scelta, "inserire") != 0 || strcmp(scelta, "esci") != 0)
            {
                conferma = NO;
            }

        } while (conferma == NO);
        if (strcmp(scelta, "cancella") == 0)
        {
            do
            {
                printf("Hai scelto di cancellare.\nInserire le coordinate del numero che vuoi cancellare\nCoordinata Y: ");
                scanf("%d", &y);
                printf("Coordinate X: ");
                scanf("%d", &x);
                printf("0:NO 1:SI\nConfermi?");
                scanf("%d", &conferma);
            } while (conferma == NO || y < 1 || y > 10 || x < 1 || x > 10);
            if (tabella[y - 1][x - 1] >= 0 && tabella[y - 1][x - 1] <= 9)
            {
                tabella[y - 1][x - 1] = '0';
            }
            else if (tabella[y - 1][x - 1] >= '0' && tabella[y - 1][x - 1] <= '9')
            {
                printf("Non puoi farlo, il numero non puo' essere cambiato!\n");
            }
            stampa_tabella(tabella);
        }
        else if (strcmp(scelta, "inserire") == 0)
        {
            do
            {
                printf("Hai selezionato di inserire un numero\nInserire le coordinate del numero che vuoi inserire\nCoordinata Y: ");
                scanf("%d", &y);
                printf("Coordinate X: ");
                scanf("%d", &x);
                printf("Seleziona il numero che vuoi inserire: ");
                scanf(" %c", &numero);
                printf("0:NO 1:SI\nConfermi?");
                scanf("%d", &conferma);
            } while (numero < '1' || numero > '9' || conferma == NO || y < 1 || y > 10 || x < 1 || x > 10);
            if (tabella[y - 1][x - 1] == '0' || tabella[y - 1][x - 1] <= 1 || tabella[y - 1][x - 1] >= 9)
            {
                tabella[y - 1][x - 1] = numero - '0';
            }
            else if (tabella[y - 1][x - 1] >= '1' && tabella[y - 1][x - 1] <= '9')
            {
                printf("Non puoi farlo, il numero non puo' essere cambiato!\n");
            }
            stampa_tabella(tabella);
        }
        do
        {
            printf("Vuoi fare un controllo?\n0:No 1:Si\n");
            scanf("%d", &conferma);
            if (conferma != SI && conferma != NO)
            {
                conferma = 3;
            }
        } while (conferma == 3);
        if (conferma == SI)
        {
            vittoria = 0;
            vittoria = vittoria + controllo1x9(tabella);
            vittoria = vittoria + controllo9x1(tabella);
            vittoria = vittoria + controllo3x3(tabella);
            if (vittoria == 3)
            {
                printf("Vinto!");
                return 0;
            }
            else if (vittoria != 3)
            {
                printf("\nSudoku non risolto, qualche numero non quadra\n\n");
            }
        }
    }
}