#include <stdio.h>

int	my_calc_max_car(int size)
{
  int nb_tour;
  int carmax;
  int gap;
  int nbligne;

  gap = 1;
  nb_tour = size -1;
  carmax = 7;
  nbligne = 4; 
  while(nb_tour > 0)
    {
      carmax = carmax - (gap * 2) + (nbligne * 2);
      nb_tour--;
      nbligne++ ;
      if (nb_tour > 0)
	{
	  carmax = carmax - (gap * 2) + (nbligne * 2);
	  nb_tour--;
	  nbligne++;
	  gap++;
	}   
    }
  return(carmax);
}

void	my_print_triangle(int size)
{
  int i;
  int nbespace;
  int nbetoile_cpt;
  int nbetoile;

  i = 0;
  nbetoile = 1;
  nbespace = my_calc_max_car(size)/ 2;
  while(i < 4)
    {
      while(nbespace > 0)
	{
	  write(1, " ",1);
	  nbespace--;
	}
      nbetoile_cpt = 0;
      while (nbetoile_cpt < nbetoile)
	{
	  write(1, "*",1);  
	  nbetoile_cpt++;
	}
      i++;
      nbespace =  my_calc_max_car(size)/ 2 - i;
      nbetoile = nbetoile + 2;
      write(1, "\n",1);
    }
}

void	my_print_trapeze(int size)
{
  int nbespace;
  int nbetoile;
  int nbligne;
  int i;
  int j;
  int z;
  int gap;
  int tour;
  
  nbespace = my_calc_max_car(size)/2-2;
  nbetoile = 5;
  nbligne = 5;
  i = 0;
  j = 0;
  z = 0;
  gap = 1;
  tour = 1;
  
  while(tour < size )
    {
      while(z < nbligne)
	{
	  while(i < nbespace)
	    {
	      write(1, " ",1);
	      i++;
	    }
	  while(j < nbetoile)
	    {
	      write(1, "*",1);
	      j++;
	    }
	  write(1, "\n",1);
	  z++;
	  i = 0;
	  j = 0;
	  nbespace = nbespace -1;
	  nbetoile = nbetoile +2;
	}
     
      if (tour % 2 == 0 )
	{
	  gap++;
	}
      tour++;
      nbespace = nbespace + 1 + gap;
      nbetoile = nbetoile - 2 - (gap * 2);
      nbligne++;
      z = 0;
    }
}
    
void	my_print_tronc(int size)
{
  int nbespace;
  int nb_pipe;
  int nbligne;
  int i;
  int j;
  int k;
  int z;
  
  nbligne = size;
  nb_pipe = 1;
  i = 0;
  j = 0;
  k = 0;
  z = 0;
  if (size > 1)
    {
      while (k < size-1)
	{
	  nb_pipe = nb_pipe + 2;
	  k++;
	  if (k < size)
	    {
	      k++;
	    }
	}
    }
  if (size == 1)
      nbespace =  my_calc_max_car(size)/2;
  if (size > 1)
      nbespace =  my_calc_max_car(size)/2 - size/2;
  while (i < nbligne)
    {
      while (j < nbespace)
	{
	  write(1, " ",1);
	  j++;
	}
      j = 0;
      while (z < nb_pipe)
	{
	  write(1 , "|", 1);
	  z++;
	}
      z = 0;
      i++;
      write(1, "\n",1);
    }
}

void sapin(int size)
{ 
  if (size > 0)
    {
      my_print_triangle(size);
      if (size > 1)
	{
	  my_print_trapeze(size);
	}
      my_print_tronc(size);
    }
}

int	main(int ac, char **av)
{
  int size;

  if (ac == 2){
    size = atoi(av[1]);
    sapin(size);
  }
  else {
    printf("wrong number of arguments\n");
      }
}
