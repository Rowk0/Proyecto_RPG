
/*
inventario tomar_objeto(inventario i, objeto o)
{
	if(i == NULL)
	{
		printf("Error: Inventario nulo\n");
		return i;
	}
	inventario aux = malloc(sizeof(struct Node));
    if(aux == NULL)
    {
        printf("Sin memoria!\n");
        return aux;
    }
    aux->p = P;
    aux->next = I;
    aux->prev = I->prev;
    I->prev = aux;
    aux->prev->next = aux;
    I->p.stock++;

    return I;
}

*/