int three_five(int number) {
   if (number % 15 == 0) {
	return 15; 
    } else if (number % 3 == 0) {
	return 3;
   } else if (number % 5 == 0) {
	return 5;
   } 
   return 1;
}