import torch
import torch.nn as nn
import pandas as pd
import joblib

# Re-define the PyTorch Model (must match the training script)
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

def predict(model_path, scaler_path, encoder_path, new_data_df):
    # Load the trained model
    # The input_dim and num_classes should ideally be saved with the model or inferred from training data
    # For this example, we'll use placeholder values that match the training script.
    # In a real application, consider saving model architecture parameters.
    dummy_input_dim = 7 # based on 'temperature', 'humidity', 'air_quality', 'soil_moisture', 'light_intensity', 'water_level', 'vibration_intensity'
    # Assuming 4 classes: 'normal', 'warning_temp', 'warning_humidity', 'warning_air_quality', 'critical_water_level'
    # We need to load the actual encoder to get num_classes reliably.
    label_encoder = joblib.load(encoder_path)
    num_classes = len(label_encoder.classes_)

    model = EarthSignalModel(dummy_input_dim, num_classes)
    model.load_state_dict(torch.load(model_path))
    model.eval() # Set model to evaluation mode

    # Load the scaler and label encoder
    scaler = joblib.load(scaler_path)

    # Preprocess new data
    features_to_scale = ['temperature', 'humidity', 'air_quality', 'soil_moisture', 'light_intensity', 'water_level', 'vibration_intensity']
    new_data_scaled = scaler.transform(new_data_df[features_to_scale])
    new_data_tensor = torch.tensor(new_data_scaled, dtype=torch.float32)

    # Make prediction
    with torch.no_grad():
        outputs = model(new_data_tensor)
        _, predicted = torch.max(outputs.data, 1)

    # Decode prediction
    predicted_labels = label_encoder.inverse_transform(predicted.numpy())
    return predicted_labels

if __name__ == '__main__':
    # Example usage:
    model_path = '/content/Divine-Earthly-Quantum-Vedic-Kernels/ai_layer/earth_signal_model.pth'
    scaler_path = 'scaler.pkl' # Assumes scaler.pkl is saved in the same directory as inference.py or current working directory
    encoder_path = 'label_encoder.pkl' # Assumes label_encoder.pkl is saved in the same directory

    # Create some dummy new data for inference
    new_data = pd.DataFrame({
        'timestamp': ['2023-01-01 13:00:00'],
        'temperature': [26.0],
        'humidity': [65.0],
        'air_quality': [85],
        'soil_moisture': [0.6],
        'light_intensity': [350],
        'water_level': [11.0],
        'vibration_intensity': [0.45]
    })

    print("Performing inference on new data...")
    predictions = predict(model_path, scaler_path, encoder_path, new_data)
    print(f"Predicted label for new data: {predictions[0]}")

    # Another example
    new_data_critical = pd.DataFrame({
        'timestamp': ['2023-01-01 14:00:00'],
        'temperature': [30.0],
        'humidity': [75.0],
        'air_quality': [100],
        'soil_moisture': [0.8],
        'light_intensity': [200],
        'water_level': [15.0],
        'vibration_intensity': [0.8]
    })
    predictions_critical = predict(model_path, scaler_path, encoder_path, new_data_critical)
    print(f"Predicted label for critical data: {predictions_critical[0]}")
