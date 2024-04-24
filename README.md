# Powering Opponent A.I. to Effectively Counter with Gradient Boosted Voting

A simple program that will use all previous inputs by you to learn and try to make the right choice upon having to choose between `attacking` or `defending`
depending on how you've responded in the past.

> [!IMPORTANT]
> In modeling phase, getting the math right.
## Mathematical Foundation / Discussion

So I want to create a rudimentary turn-based enemy "AI" with predictive modeling that grows alongside the user.

First, I want to see what classification method is optimal for what I want to do.

### Classification Models - Gradient Boosted Regression Trees

I think this model works best (as of now) because not only do I have scalability, but I also have a pretty nice
voting method to improve the regression tree learner. 

### Math

So for my algorithm, I'll be using Friedman's stochastic gradient boosting algorithm, which can be portrayed by:

1. Computing an `F₀` constant so I can iteratively create my trees later. This can be done through the following:

![constant](https://github.com/PrideInt/decision-to-grow/assets/20098992/5bd4471e-f2e9-479b-92af-88ea788fcd09)

Our predicted value is defined by `p` and our observed values are defined by `yᵢ`.

Our loss function is defined by `L(yᵢ,p)`. I'll be using the MSE (mean squared error) loss function, which here, can be defined as `1/2(yᵢ, p)^2`.

Here, we'll be finding `p` that minimizes the sum of the loss function, which is really just the average of `∀(i) ϵ y`.

2. Now in the for loop iteration step from `n` to `N`, where `n = 1` and `100 < N < 1000`, I'll be computing my pseudo-residuals by solving a differentiable gradient with respect to our loss function.

I'll begin by computing my pseudo-residuals `r`:

![residual](https://github.com/PrideInt/decision-to-grow/assets/20098992/b73fc574-5d52-4940-b9ea-329f08d30572)

Then create and fit my trees `R`.

I'll then compute my predicted values `p`:

![predicted](https://github.com/PrideInt/decision-to-grow/assets/20098992/650cc812-3290-401e-a1ea-9322060507c1)

And finally update my model to compensate for any errors as well as introducing learning rate `l` to better accurately predict a value:

![update](https://github.com/PrideInt/decision-to-grow/assets/20098992/e52ddff3-5ee0-4cd6-81b8-7821bdd0bc8c)

3. My predicted values would range between `attacking` = `0 < a < 1`, `defending` = `1 < d < 2` and `healing` = `2 < h < 3`. I'll classify the users based on these values alone whether or not the user falls between any of the ranges respectively.

### Red-Lighted

**Naive Bayes** was my initial method of classification, which is not bad. It's effective and easy to implement, but
I don't think this can best solve my objective as naive Bayes is not as scalable as I'd like. I want my enemy
to learn and grow, and I think naive Bayes may end up becoming too inaccurate in predicting the user.

**Logistic regression** is also great. Though, because its basis lies in the Bernoulli distribution, it doesn't
solve the multiclass problem that I'll face. I can implement a multiclass logistic regression algorithm, but that
would require me to do more work than I'd like to.

**Support vector machines** faces a similar issue with naive Bayes. Over time when input data becomes too complex,
which it will, since user inputs can vary, SVMs will end up giving me inaccurate predictions.

**k-NN** will not work well. Like naive Bayes and support vector machines, this problem lies in how the data looks
in the future, which cannot be solved through mode classification. Majority voting isn't good in this situation,
the user can work their way around this very easily and manipulate the enemy.

**Decision trees** are too weak, but this can be solved with gradient boosting. Something to think about. Though,
**regression trees** can work better.
