import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder

# 1. Define the Dataset Class
class EarthDataset(Dataset):
    def __init__(self, features, labels):
        self.features = torch.tensor(features, dtype=torch.float32)
        self.labels = torch.tensor(labels, dtype=torch.long)

    def __len__(self):
        return len(self.labels)

    def __getitem__(self, idx):
        return self.features[idx], self.labels[idx]

# 2. Define the PyTorch Model
class EarthSignalModel(nn.Module):
    def __init__(self, input_dim, num_classes):
        super(EarthSignalModel, self).__init__()
        self.fc1 = nn.Linear(input_dim, 64)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(64, 32)
        self.fc3 = nn.Linear(32, num_classes)

    def forward(self, x):
        x = self.fc1(x)
        x = self.relu(x)
        x = self.fc2(x)
        x = self.relu(x)
        x = self.fc3(x)
        return x

# 3. Training Pipeline
def train_model(data_path, model_save_path='earth_signal_model.pth'):
    # Load data
    df = pd.read_csv(data_path)

    # Preprocessing
    features = df[['temperature', 'humidity', 'air_quality', 'soil_moisture', 'light_intensity', 'water_level', 'vibration_intensity']]
    labels = df['label']

    # Encode labels
    label_encoder = LabelEncoder()
    labels_encoded = label_encoder.fit_transform(labels)
    num_classes = len(label_encoder.classes_)

    # Scale features
    scaler = StandardScaler()
    features_scaled = scaler.fit_transform(features)

    # Split data
    X_train, X_test, y_train, y_test = train_test_split(features_scaled, labels_encoded, test_size=0.2, random_state=42)

    # Create datasets and dataloaders
    train_dataset = EarthDataset(X_train, y_train)
    test_dataset = EarthDataset(X_test, y_test)
    train_loader = DataLoader(train_dataset, batch_size=4, shuffle=True)
    test_loader = DataLoader(test_dataset, batch_size=4, shuffle=False)

    # Model, Loss, Optimizer
    input_dim = X_train.shape[1]
    model = EarthSignalModel(input_dim, num_classes)
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=0.001)

    # Training loop
    num_epochs = 10
    print("Starting model training...")
    for epoch in range(num_epochs):
        model.train()
        for inputs, targets in train_loader:
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, targets)
            loss.backward()
            optimizer.step()
        print(f'Epoch {epoch+1}/{num_epochs}, Loss: {loss.item():.4f}')

    print("Model training finished.")

    # Evaluation (simple example)
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for inputs, targets in test_loader:
            outputs = model(inputs)
            _, predicted = torch.max(outputs.data, 1)
            total += targets.size(0)
            correct += (predicted == targets).sum().item()
    print(f'Accuracy on test data: {(100 * correct / total):.2f}%')

    # Save the trained model
    torch.save(model.state_dict(), model_save_path)
    print(f"Model saved to {model_save_path}")
    
    # Save label encoder for inference
    import joblib
    joblib.dump(label_encoder, 'label_encoder.pkl')
    joblib.dump(scaler, 'scaler.pkl')
    print("Scaler and LabelEncoder saved.")

if __name__ == '__main__':
    # Adjust the data_path based on your environment
    train_model('/content/Divine-Earthly-Quantum-Vedic-Kernels/datasets/sample_earth_data.csv',
                '/content/Divine-Earthly-Quantum-Vedic-Kernels/ai_layer/earth_signal_model.pth')

