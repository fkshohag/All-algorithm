# ** MULTI LALYER PERCEPTRON **
# Import required libraries :
import numpy as np
import time
# Define input features :
input_features = np.array([[0,0],[0,1],[1,0],[1,1]])
# Define target output :
target_output = np.array([[0,1,1,0]])
# Reshaping our target output into vector :
target_output = target_output.T
# Define weights, thresholds randomly:
# w13 = 0.5
# w23 = 0.4
# w14 = 0.9
# w24 = 1.0
# w35 = -1.2
# w45 = 1.1
# theta3 = 0.8

# theta4 = -0.1
# theta5 = 0.3

# 56356 iteration
# value of : w13, w23, w14, w24, w35, w45, theta3, theta4, theta5
# Final Update [4.75176404] [4.75166639] [6.38293073]
# [6.38296888] [-10.39086308] [9.77647536] [7.29111803]
# [2.8402291] [4.56069102]

w13 = 4.75176404
w23 = 4.75166639
w14 = 6.38293073
w24 = 6.38296888
w35 = -10.39086308
w45 = 9.77647536
theta3 = 7.29111803
theta4 = 2.8402291
theta5 = 4.56069102

print("value of : w13, w23, w14, w24, w35, w45, theta3, theta4, theta5")
print("randomly initialized ", w13, w23, w14, w24, w35, w45, theta3, theta4, theta5)
lr = 0.1 # learning rate

# Sigmoid function :
def sigmoid(x):
	return 1/(1+np.exp(-x))

# Main logic for neural network :
inputs = input_features

y3 = y4 = y5 = del3 = del5 = del5 = 0
error = [0]*4
# Running our code 10000 times :
epoch = 0
tic = time.time()


while True:
	for i in range(4):
		y3 = sigmoid(inputs[i][0]*w13+inputs[i][1]*w23-theta3)
		y4 = sigmoid(inputs[i][0]*w14+inputs[i][1]*w24-theta4)
		y5 = sigmoid(y3*w35+y4*w45-theta5)
		error[i] = target_output[i]-y5
		print("prediction, error = ",y5, error[i])

		# error gradiant for neuron 5
		del5 = y5 * (1-y5)* error[i]
		# weight trainig
		dW35 = lr * y3 * del5
		dW45 = lr * y4 * del5
		dTheta5 = lr * -1 * del5

		# error gradiant for neuron 3, 4
		del3 = y3 * (1-y3) * del5 * w35
		del4 = y4 * (1-y4) * del5 * w45
		# weight training
		dW13 = lr * inputs[i][0] * del3
		dW23 = lr * inputs[i][1] * del3
		dTheta3 = lr * -1 * del3

		dW14 = lr * inputs[i][0] * del4
		dW24 = lr * inputs[i][1] * del4
		dTheta4 = lr * -1 * del4
		# update the weights and thresholds
		w13 += dW13
		w14 += dW14
		w23 += dW23
		w24 += dW24
		w35 += dW35
		w45 += dW45
		theta3 += dTheta3
		theta4 += dTheta4
		theta5 += dTheta5
	sum = 0
	for i in range(4):
		sum += error[i]*error[i]
	print("error sum = ", sum)
	if(sum<=0.001):
		break
	epoch += 1

print("epoch = ",epoch)
toc = time.time()
print("time is ",(toc-tic)*1000," ms")
print("value of : w13, w23, w14, w24, w35, w45, theta3,theta4, theta5")
print("Final Update ", w13, w23, w14, w24, w35, w45,
theta3, theta4, theta5)
'''this MLP (Multilayer Perveptron) function
will take input x1 and x2 (inputs will be given manually
for now)
and will perform X-OR operation

based on the previous updated weights (w13, w23, w14, w24)
and thresholds (theta3, theta4, theta5) '''
def MLP(x1, x2):
	y3 = NN(x1,w13,x2,w23,theta3)
	y4 = NN(x1,w14,x2,w24,theta4)
	y5 = NN(y3,w35,y4,w45,theta5)
	print("predicted ",y5)

# inputs are like X-OR gates inputs
# (0,0) = 0
# (0,1) = 1
# (1,1) = 0
# (1,0) = 1

MLP(1,0)

