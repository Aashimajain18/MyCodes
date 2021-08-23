int PrintAllNodesatDistanceKfromTargetNode(node* root,node*target,int k){
if(root==NULL){
	return -1;
}
//reach the target
if(root==target){
	print_k_level(root,k);
	return 0;
}

//next step is to go back to the ancestors
int dl=PrintAllNodesatDistanceKfromTargetNode(root->left,target,k);
if(dl!=-1){
	//there are 2 cases
	//either u need to rpint the ancestor itself or go to the right subtree of the ancestor
	if(dl+1==k){
		//print ancestor
		cout<<root->data<<" ";
	}
	else{
		print_k_level(root->right,k-dl-2);
	}
	return 1+dl;
}
int dr=PrintAllNodesatDistanceKfromTargetNode(root->right,target,k);
if(dr!=-1){
	//there are 2 cases
	//either u need to rpint the ancestor itself or go to the right subtree of the ancestor
	if(dr+1==k){
		//print ancestor
		cout<<root->data<<" ";
	}
	else{
		print_k_level(root->left,k-dr-2);
	}
	return 1+dr;
}
//node wasn't present in left or right subtree
return -1;
}
