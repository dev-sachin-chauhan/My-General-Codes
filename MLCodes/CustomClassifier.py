
from scipy.spatial import distance

def euclidean(a, b):
	return distance.euclidean(a, b)

#Custom Classifier 
class CustomClassifier():
	def fit(self, X_train, Y_train):
		self.X_train = X_train
		self.Y_train = Y_train

	def predict(self, X_test):
		predictions = []
		for row in X_test:
			label = self.closest(row)
			predictions.append(label)
		return predictions

	def closest(self, row):
		closest_dist = euclidean(row, self.X_train[0])
		best_indx = 0
		for i in range(len(self.X_train)) :
			dis = euclidean(row, self.X_train[i])
			if dis < closest_dist:
				closest_dist = dis
				best_indx = i
		return self.Y_train[best_indx]

#Load data set
from sklearn import datasets
iris = datasets.load_iris()

X = iris.data
Y = iris.target

#create half of the dataset as testing and other for learning
from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = .5)

#Select classifier for prediction
#from sklearn.neighbors import KNeighborsClassifier
#classifier = KNeighborsClassifier();

#Using CustomClassifier based on K Neighbor 
classifier = CustomClassifier();

#Train the classifier
classifier.fit(X_train, Y_train)

#predict the data for test
prediction = classifier.predict(X_test)

#calculate accuracy with test data
from sklearn.metrics import accuracy_score
print accuracy_score(Y_test, prediction)
