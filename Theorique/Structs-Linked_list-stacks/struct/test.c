/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:31:20 by alamrani          #+#    #+#             */
/*   Updated: 2026/01/05 15:31:23 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
char    *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

struct Player
{
    int age;
    char name[50];
};


int main()
{
    !struct = collection of related members ("variables")
    *          they can be of different data types
    *          listed undeer one name in a block of memory
    ?          VERY SIMILAR to Classes in other languages (but no methods)         
    struct Player player1;
    struct Player player2;
    
    ! If you use technique, you should use strcpy, you can't assign a string
    ft_strcpy(player1.name, "Abdelhamid Lamrani");
    player1.age = 24;
    ft_strcpy(player2.name, "Youness sba3");
    player2.age = 22;
    printf("Player Mr %s, he is %d years old.\n", player1.name, player1.age);
    printf("Player Mr %s, he is %d years old.\n", player2.name, player2.age);
    
    //* however, this technique is working
    struct Player p3 = {23, "Simo ZatZat"};
    printf("Player Mr %s, he is %d years old.\n",p3.name, p3.age);
    TODO: Both techniques are for setting or modifying values.

    ! Copy Structures
    ? You can also assign one structure to another.
    struct Player p4;
    p4 = player1;
    printf("Player Mr %s, he is %d years old.\n",p4.name, p4.age);
    * Modifying
    p4.age = 32;
    ft_strcpy(p4.name, "salah rijal");
    printf("New P4 Name: %s, he is %d years old.\n",p4.name,p4.age);

} */

struct Owner {
  char firstName[30];
  char lastName[30];
};

struct Car {
  char brand[30];
  char model[30];
  int year;
  struct Owner owner; //Nested struct
};

int main() {
//   struct Car car1 = {"BMW", "X5", 1999};
//   struct Car car2 = {"Ford", "Mustang", 1969};
//   struct Car car3 = {"Toyota", "Corolla", 2011};

//   printf("%s %s %d\n", car1.brand, car1.model, car1.year);
//   printf("%s %s %d\n", car2.brand, car2.model, car2.year);
//   printf("%s %s %d\n", car3.brand, car3.model, car3.year);
/*
    ! Nested Structs
    ? A structure can also contain another structure as a member. This is called a nested structure,
    ? and it is useful when you want to group related data together in layers:
*/
struct Owner owner1 = {"Abdelhamid", "Lamrani"};
    struct Car car1 = {"Ford", "Mustang", 1969, owner1};
    printf("Car: %s, Model %s published in (%d)\n", car1.brand, car1.model, car1.year);
    printf("Owner: %s %s\n", car1.owner.firstName, car1.owner.lastName);
    return 0;
}