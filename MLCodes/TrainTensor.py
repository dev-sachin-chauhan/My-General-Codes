import numpy as np

#Collecting data
X = np.array([[0,0,1],[0,1,1],[1,0,1],[1,1,1]])
Y = np.array([[0],[1],[1],[0]])

print X

print Y

#Builing model
numechoes = 60000

#Initailising weights from -1 to 1
sync0 = 2*np.random.random((3,4)) - 1
sync1 = 2*np.random.random((4,1)) - 1

print sync0

print sync1

def nonLinear(x , deriv = False):
	if deriv == True:
		return x*(1-x)
	return 1/(1+np.exp(-x))

#Train model
for i in xrange(numechoes):
	#Feed forward through layers
	l0 = X
	l1 = nonLinear(np.dot(X,sync0))
	l2 = nonLinear(np.dot(l1,sync1))

	#The error function or the cost value
	l2_error = Y - l2

	if (i % 10000) == 0:
		print "Error :" + str(np.mean(np.abs(l2_error)))

	#Identify direction of target value
	l2_delta = l2_error * nonLinear(l2, deriv = True)

	#How much l1 contributed to l2 error
	l1_error = l2_delta.dot(sync1.T)

	#Identify direction of target value
	l1_delta = l1_error * nonLinear(l1, deriv = True)

	sync1 += l1.T.dot(l2_delta)
	sync0 += l0.T.dot(l1_delta)

#Predict value
l0 = np.array([[0,0,0],[0,1,0],[1,0,0],[1,1,0]])
l1 = nonLinear(np.dot(X,sync0))
l2 = nonLinear(np.dot(l1,sync1))
print l2
