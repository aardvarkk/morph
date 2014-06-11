# Morph

## Approach

* Gather a set of images to use
* Select keypoints in the images
* Find affine transformation to minimize error between transitions
 * This would tell you the static flip, rotation, and scale of the image to match to previous/next
 * Optional: determine optimal overall image ordering based on affine transformations
