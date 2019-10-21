# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 15:46:51 by cbretagn          #+#    #+#              #
#    Updated: 2019/10/21 17:44:47 by cbretagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

sep=" ";
total=0;

echo 'Hi ! Please select pile size : \c'
read a;
echo 'Please select number of times you want to run the process : \c'
read b;

for k in `seq 1 $b`;
do
{
	str="";
	for i in `seq 1 $a`;
	do
	{
		rand=$RANDOM;
		str="$str$sep$rand";	
	}
	done
	tmp=`./push_swap $str | wc -l | sed -e 's/ //g' | tr -d '\n'`;
	let total+=$tmp;
}
done
let total/=$b;
echo $total
