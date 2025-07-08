class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;     // Current node at the current level
        Node* head = nullptr;  // Head of the next level
        Node* prev = nullptr;  // Previous node on the next level

        while (curr) {
            while (curr) {
                // Left child
                if (curr->left) {
                    if (prev) {
                        prev->next = curr->left;
                    } else {
                        head = curr->left;
                    }
                    prev = curr->left;
                }

                // Right child
                if (curr->right) {
                    if (prev) {
                        prev->next = curr->right;
                    } else {
                        head = curr->right;
                    }
                    prev = curr->right;
                }

                // Move to next node on the current level
                curr = curr->next;
            }

            // Move to the next level
            curr = head;
            head = nullptr;
            prev = nullptr;
        }

        return root;
    }
};
