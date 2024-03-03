#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            printf("%d ", tabella[y][x] - '0');
        }
        printf("\n");
    }
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

int main()
{
    char tabella[9][9] = {0};

    srand(time(NULL));

    if (riempi_tabella(tabella, 0, 0))
    {
        cambio_valori(tabella);
        printf("Sudoku generato:\n");
        stampa_tabella(tabella);
    }
    else
    {
        printf("Impossibile generare una tavola di Sudoku valida.\n");
    }

    return 0;
}