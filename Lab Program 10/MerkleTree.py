import hashlib
class MerkleNode:
    def __init__(self, data=None, left=None, right=None):
        self.data = data # Holds the data (hash) of the node
        self.left = left # Left child (MerkleNode)
        self.right = right # Right child (MerkleNode)
def hash_data(data):
    """Hashes the input data using SHA-256."""
    return hashlib.sha256(data.encode('utf-8')).hexdigest()
def create_leaf_node(data):
    """Creates a leaf node containing the hash of the transaction."""
    return MerkleNode(data=hash_data(data))
def create_internal_node(left, right):
    """Creates an internal node by hashing the concatenation of the left and right node hashes."""
    combined_hash = left.data + right.data
    return MerkleNode(data=hash_data(combined_hash), left=left, right=right)
def build_merkle_tree(leaf_nodes):
    """Recursively builds a Merkle tree from a list of leaf nodes."""
    if len(leaf_nodes) == 1:
        return leaf_nodes[0]
# If there's an odd number of nodes, duplicate the last one
    if len(leaf_nodes) % 2 == 1:
        leaf_nodes.append(leaf_nodes[-1])
    parent_nodes = []
    for i in range(0, len(leaf_nodes), 2):
        parent_nodes.append(create_internal_node(leaf_nodes[i], leaf_nodes[i+1]))
    # Recursively build the tree with parent nodes
    return build_merkle_tree(parent_nodes)
# Example transactions (strings for simplicity)
transactions = [
'Tx1: Alice -> Bob 100 BTC',
'Tx2: Bob -> Charlie 50 BTC',
'Tx3: Charlie -> Dave 25 BTC',
'Tx4: Dave -> Eve 10 BTC'
]
# Create leaf nodes for each transaction
leaf_nodes=[]
for tx in transactions:
    leaf_nodes.append(create_leaf_node(tx))
# Build the Merkle tree
root = build_merkle_tree(leaf_nodes)
# Print the Merkle Root
print("Merkle Root Hash:")
print(root.data)
print("Merkle Root Hash:")
print(root.data)