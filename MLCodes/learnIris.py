from sklearn.datasets import load_iris
from sklearn import tree
import numpy as np

#Uncomment If you want to see the data
#printData(iris)
#importing dataset of iris
iris = load_iris()
test_indx = [0,50,100]

#create training dataset
trainingData = np.delete(iris.data, test_indx, axis = 0);
trainingTarget = np.delete(iris.target, test_indx);

#create tessting dataset
testingData = iris.data[test_indx]
testingTarget = iris.target[test_indx]

#create Classifier
cls = tree.DecisionTreeClassifier()
cls.fit(trainingData, trainingTarget)

print testingTarget
print cls.predict(testingData)

def printData(iris):
	print iris.feature_names
	print iris.target_names	
	print iris.data[0]
	print iris.target[0]