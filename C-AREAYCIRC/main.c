int main()
{
   int radio_c;
   float valor_pi=3.14, area_c, circun_c;

   //Pedir radio del circulo
   printf("\nIngresar radio del circulo: ");
   //Guardando datos
   scanf("%d",&radio_c);

   //Calcular y mostrar area
   area_c = valor_pi * radio_c * radio_c;
   printf("\nArea del circulo es: %f",area_c);

   //Calcular y mostrar circunferencia
   circun_c = 2 * valor_pi * radio_c;
   printf("\nCircunferencia del circulo es: %f",circun_c);

   return(0);
}