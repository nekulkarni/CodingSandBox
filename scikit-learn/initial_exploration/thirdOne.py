##################
#                #
# Classification #
#                #
##################

# load dataset

from sklearn.datasets import load_iris
irisdata = load_iris()
X = irisdata.data
y = irisdata.target
print X.shape                   # n_samples X n_features
print y.shape                   # n_samples (1 label per sample)


from sklearn.svm import LinearSVC   # create a model
svClf = LinearSVC()
print svClf                     # prints hyperparameters of the model

svClf.fit(X, y)                 # train the model
print svClf.coef_               # parameters learned by the model
predicted = svClf.predict(X)    # now predict based on training


# Now we want to see how well our classifier's working

from sklearn import metrics
accuracy_linsvc = metrics.accuracy_score(y, predicted) # accuracy
print "accuracy_linsvc:", accuracy_linsvc
cmat_linsvc = metrics.confusion_matrix(y, predicted)   # confusion matrix
print cmat_linsvc