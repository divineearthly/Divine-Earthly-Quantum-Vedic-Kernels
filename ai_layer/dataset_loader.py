import pandas as pd
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.model_selection import train_test_split
import joblib

class DatasetLoader:
    def __init__(self, data_path, scaler_path='scaler.pkl', encoder_path='label_encoder.pkl'):
        self.data_path = data_path
        self.scaler_path = scaler_path
        self.encoder_path = encoder_path
        self.df = None
        self.features = None
        self.labels = None
        self.scaler = None
        self.label_encoder = None

    def load_and_preprocess(self, test_size=0.2, random_state=42, train_mode=True):
        self.df = pd.read_csv(self.data_path)

        # Define features and labels
        feature_cols = ['temperature', 'humidity', 'air_quality', 'soil_moisture', 'light_intensity', 'water_level', 'vibration_intensity']
        self.features = self.df[feature_cols]
        self.labels = self.df['label']

        if train_mode:
            # Scale features
            self.scaler = StandardScaler()
            features_scaled = self.scaler.fit_transform(self.features)
            joblib.dump(self.scaler, self.scaler_path)
            print(f"Scaler saved to {self.scaler_path}")

            # Encode labels
            self.label_encoder = LabelEncoder()
            labels_encoded = self.label_encoder.fit_transform(self.labels)
            joblib.dump(self.label_encoder, self.encoder_path)
            print(f"LabelEncoder saved to {self.encoder_path}")

            # Split data for training
            X_train, X_test, y_train, y_test = train_test_split(features_scaled, labels_encoded, test_size=test_size, random_state=random_state)
            return X_train, X_test, y_train, y_test
        else:
            # For inference, load pre-trained scaler and encoder
            try:
                self.scaler = joblib.load(self.scaler_path)
                self.label_encoder = joblib.load(self.encoder_path)
            except FileNotFoundError:
                print("Error: Scaler or LabelEncoder not found. Please train the model first.")
                return None, None, None, None
            
            features_scaled = self.scaler.transform(self.features)
            labels_encoded = self.label_encoder.transform(self.labels)
            return features_scaled, labels_encoded

    def get_num_classes(self):
        if self.label_encoder:
            return len(self.label_encoder.classes_)
        return None

    def get_input_dim(self):
        if self.features is not None:
            return self.features.shape[1]
        return None

if __name__ == '__main__':
    data_path = '/content/Divine-Earthly-Quantum-Vedic-Kernels/datasets/sample_earth_data.csv'
    loader = DatasetLoader(data_path)

    print("
--- Training Mode Test ---")
    X_train, X_test, y_train, y_test = loader.load_and_preprocess(train_mode=True)
    if X_train is not None:
        print(f"X_train shape: {X_train.shape}")
        print(f"y_train shape: {y_train.shape}")
        print(f"Number of classes: {loader.get_num_classes()}")
        print(f"Input dimension: {loader.get_input_dim()}")

    print("
--- Inference Mode Test ---")
    # Simulate loading for inference after training (scaler and encoder should be saved)
    loader_inference = DatasetLoader(data_path)
    features_scaled, labels_encoded = loader_inference.load_and_preprocess(train_mode=False)
    if features_scaled is not None:
        print(f"Features scaled shape (inference): {features_scaled.shape}")
        print(f"Labels encoded shape (inference): {labels_encoded.shape}")
        print(f"Number of classes (inference): {loader_inference.get_num_classes()}")
