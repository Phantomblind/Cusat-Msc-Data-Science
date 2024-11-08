#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
} *root = NULL, *temp = NULL;

struct node* createNode(int data) {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->value = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->value) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct node* findMin(struct node* node) {
    struct node* current = node;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) return root;

    if (data < root->value) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->value) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->value == data) {
        return root;
    }
    if (data < root->value) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d - ", root->value);
        inorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display (In-order Traversal)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted.\n", value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                temp = search(root, value);
                if (temp != NULL) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value %d deleted from the tree.\n", value);
                break;
            case 4:
                printf("In-order traversal of the BST: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
