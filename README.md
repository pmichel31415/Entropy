# Entropy

C++ program calculating the entropy of a language based on a corpus of texts.

### Usages :

The usage template is as follow : `./entropy [command] [store_filename] [additional options]`

More precisely, there are three commands available :

1. `assimilate` takes a text file as imput and computes the conditionnal probability of appearance of each character/word(*) assuming it follows a nth order stationary markov model. All data is then stored in a file. The exact usage is 
    * `./entropy assimilate [store_filename] [input_filename] [markov_order]`
2. `calculate` computes the entropy of the markov model (see explanation for more details). Usage :
    * `./entropy calculate [store_filename] [markov_order]`
3. `generate` is undoubtedly the most fancy feature. It randomly generates text based on the probabilities computed with the `assimilate` command. Usage :
    * `./entropy generate [store_filename] [output_filename] [text_length] [markov_order]`

### Explanation

We assume the frequency of each letter follows a stationary markov model of order k. This means that the probability
![equation 1](https://latex.codecogs.com/svg.latex?%5Cinline%20%5Cdpi%7B200%7D%20%5Csmall%20P%28X_n%3Dx%7CY_%7Bn-1%7D%3Dy_%7Bn-1%7D%2C...%2CY_0%3Dy_0%29) 
equals 
![equation 2](https://latex.codecogs.com/svg.latex?%5Cinline%20%5Cdpi%7B200%7D%20P%28X_n%3Dx%7CY_%7Bn-1%7D%3Dy_%7Bn-1%7D%2C...%2CY_%7Bn-k%7D%3Dy_%7Bn-k%7D%29) 
for all n. More precisely, it equals ![equation 2](https://latex.codecogs.com/svg.latex?%5Cdpi%7B200%7D%20p%28x%2Cy_%7Bn-1%7D%2C...%2Cy_%7Bn-k%7D%29)
with p being a function independent from n (the markov chain is supposed stationnary).


### Python scripts

I added a few python scripts to show how the code can be used to calulate the entropy of, say, french.

* First you should download the raw material using :

   $ python Scripts/french_texts_dl.py
   $ python Scripts/code_civil_dl.py
   
(You may want to launch the second script in the Text folder created by the first one to regroup all files)

* Then launch the program on all files (don't forget to adjust the markov order in the python file)
   
   $ python Scripts/assimilate_folder.py

Of course you can change any parameter you want in the python files ;)
