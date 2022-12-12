int main()
{
   int radius_c;
   float pi_value = 3.14, area_c, circun_c;

   // Ask for radius
   printf("\nEnter circle radius: ");
   // save radius
   scanf("%d", &radius_c);

   // calculate and show area
   area_c = pi_value * radius_c * radius_c;
   printf("\nArea of the circle: %f", area_c);

   // calculate and show circumference
   circun_c = 2 * pi_value * radius_c;
   printf("\nCirc of the circle: %f", circun_c);

   return (0);
}