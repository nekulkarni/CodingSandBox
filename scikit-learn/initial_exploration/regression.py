##############
#            #
# Regression #
#            #
##############


from sklearn.datasets import load_boston
import matplotlib.pyplot as plt

# load home price data

data = load_boston()
(numSamples, numFeatures) = data.data.shape
print "numSamples:", numSamples
print "numFeatures:", numFeatures

# visualize all houseprices as a histogram

plt.hist(data.target)
plt.show()


# try scatter plots of the features versus the target
# are there any features with a strong correlation with
# the target value? Any that don't?

column_0 = data.data[:, 0]
plt.scatter(column_0, data.target)
plt.show()


# Now use the LinearRegression predictor to predict the
# price of a new house.

from sklearn.linear_model import LinearRegression# Estimator class
clf = LinearRegression()                         # instantiate the model
clf.fit(data.data, data.target)                  # train it with our data
predicted = clf.predict(data.data)               # predict targets for data
plt.scatter(data.target, predicted)              # plot true vs predicted
plt.plot([0,50], [0,50], '--k')
plt.title('LinearRegression')
plt.axis('tight')
plt.xlabel('True price ($1Ks)')
plt.xlabel('Predicted price ($1Ks)')
plt.show()

# Ok. Now lets try another regressor, DecisionTreeRegressor

from sklearn.tree import DecisionTreeRegressor # Estimator class
clf = DecisionTreeRegressor()                  # instantiate the model
clf.fit(data.data, data.target)                # fit model to data(train)
predicted = clf.predict(data.data)             # predict targets for data
plt.scatter(data.target, predicted)            # plot true vs predicted
plt.plot([0,50], [0,50], '--k')
plt.title('DecisionTreeRegressor')
plt.axis('tight')
plt.xlabel('True price ($1Ks)')
plt.xlabel('Predicted price ($1Ks)')
plt.show()



