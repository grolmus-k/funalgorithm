# funalgorithm

## Install the package by downloading the package folder

Steps to run functions in the package:

1. Download the funalgorithm folder.

2. Open R. Make sure you are working in the directory where the folder is stored.

3. Instal "devtools" if not done already

  install.packages("devtools")
  
4. Load devtools package

  library(devtools)
  
5. Locally instal "funalgorithm" 

  install_local("funalgorithm",force=TRUE)

6. Load funalgorithm package

  library(funalgorithm)

You are ready to use the functions from funalgorithm package!

You can run the following example to make sure it works.

preference_table_1 <- data.frame (
"A" = c("c","b","d","a"),
"B" = c("b","a","c","d"),
"C" = c("b","d","a","c"),
"D" = c("c","a","d","b")
)

preference_table_2 <- data.frame (
"a" = c("A","B","D","C"),
"b" = c("C","A","D","B"),
"c" = c("C","B","D","A"),
"d" = c("B","A","C","D")
)


rcpp_marshall_dataframe(preference_table_1)

#$B        'b''a''c''d'

#$D        'c''a''d''b'

#$C        'b''d''a''c'

#$A        'c''b''d''a'

rcpp_stable_marriage(preference_table_1,preference_table_2)

#a:   'B' d:   'A' b:   'C' c:   'D' A:   'd' C:   'b' D:   'c' B:   'a'

The data can also be inputted in list of vector of string format as follows:

preference_table_1l <- list(c("c","b","d","a"),c("b","a","c","d"),c("b","d","a","c"),c("c","a","d","b"))

names(preference_table_1l) <- c("A","B","C","D")

preference_table_2l <- list(c("A","B","D","C"),c("C","A","D","B"),c("C","B","D","A"),c("B","A","C","D"))

names(preference_table_2l) <- c("a","b","c","d")

rcpp_stable_marriage(preference_table_1l,preference_table_2l)

## Install the package directly from github

To download the package from github:
1. Instal "devtool" if not done already

  install.packages("devtools")
  
2. Load devtools package

  library(devtools)

3. Download the package from github

  devtools::install_github("grolmus-k/funalgorithm",force=TRUE)
  
4. Load funalgorithm package

  library(funalgorithm)

You are ready to use the functions from funalgorithm package!

Again, check that it works using the example from Task 1.
