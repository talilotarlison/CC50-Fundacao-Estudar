// Garbage Values(valores de lixo)

// Vamos dar uma olhada no seguinte:

int main(void)
{
    int x;
    int y;
    x = malloc(sizeof(int));
    x = 42;
    y = 13;
    y = x;
    *y = 13;
}
