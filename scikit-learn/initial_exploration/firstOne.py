from sklearn.datasets import load_digits
from matplotlib import pyplot as plt

digits = load_digits()

print digits.keys() 
# prints ['images', 'data', 'target_names', 'DESCR', 'target']

n_samples, n_features = digits.data.shape
print (n_samples, n_features)

print digits.data[0]
print digits.target

print digits.data.shape     # (1797, 64)
print digits.images.shape   # (1797, 8, 8)

#set up the figure
fig = plt.figure(figsize=(6,6)) # figure size in inches
fig.subplots_adjust(left=0, right=1, bottom=0, top=1, hspace=0.05, wspace=0.05);

# plot the digits: each image is 8x8 pixels
for i in range(64):
    ax = fig.add_subplot(8, 8, i+1, xticks=[], yticks=[])
    ax.imshow(digits.images[i], cmap=plt.cm.binary)

    # label the image with the target value
    ax.text(0, 7, str(digits.target[i]))


plt.show()




