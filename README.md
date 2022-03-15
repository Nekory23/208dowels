# 208dowels
{EPITECH} | Second year | Math project

A power hammer mass produces dowels. Sometimes, some pieces are defective, and the whole process requires quality control: 100 samples of 100 pieces are randomly taken, and defective pieces are numbered. We get what we call an observed serial. Then, a statistical fit is done using the binomial distribution, and validated using the χ2 test.

Let’s note x the number of defective pieces, Oxthe size of the observed sample, and Txthe theoretical size. 
To ensure the consistency of the fit, statistical classes which have less than 10 elements are merged until there are only classes with 10 or more elements. Smallest classes are aggregated first.
Finally, with the number of constraints for the fit being 2, the degrees of freedom parameter ν is equal to
the number of classes minus 2.

Your program will take 9 integers as inputs, representing respectively O0, O1, ... ,O8+ and will output:
1. an array showing observed and theoretical sizes for each statistical class (with totals)
2. the chosen probability distribution for the fit,
3. the value of χ2,
4. the value of ν,
5. the value range in which the probability falls if the fit is valid.

See the subject for further details !

========================

Grade : A | Mark : 13.3

| Category        | Percentage | Tests     | Crash ? |
|-----------------|------------|-----------|---------|
| basic           | 100%       | 3/3       | x       |
| fit             | 33.3%      | 1/3       | x       |
| fit (eval)      | 66.7%      | 2/3       | x       |
| rigor           | 100%       | 7/7       | x       |
| validity        | 66.7%      | 2/3       | x       |
| validity (eval) | 66.7%      | 2/3       | x       |
| **End score**   | **77.3%**  | **17/22** | **No**  |

Made with Quentin TREHEUX ([LuciferBahamut](https://github.com/LuciferBahamut))

Beware of -42 Epitech students !!!
