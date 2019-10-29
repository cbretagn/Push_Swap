# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    random.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 15:46:51 by cbretagn          #+#    #+#              #
#    Updated: 2019/10/29 17:47:39 by cbretagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

total=0;

echo 'Hi ! Please select pile size : \c'
read a;
echo 'Please select number of times you want to run the process : \c'
read b;

for k in `seq 1 $b`;
do
{
	ARG=`ruby -e "puts (1..$a).to_a.shuffle.join(' ')"`;
	tmp=`./push_swap $ARG | wc -l | sed -e 's/ //g' | tr -d '\n'`;
	let total+=$tmp;
}
done
let total/=$b;
echo $total
