So far, what we did was make a very basic parking space simulation where we can do basic commands such as occupy space, marking things under maint, freeing space (removes occupied vehicle ) 
and marking avaliable (removes under maint). 

outside of these command they also have have basic logic such as:
making sure you can only occupy space if the space is not occupied and also is not under maintenance (lets the user know that its not avaliable if either is the case)
First making sure that a parking space is not occupied before marking under maintenance (lets the user know that its not possible to be under maintenance since a vehicle is currently there)
etc 


Currently we dont check for things like input validaton and its still missing a lot of methods.