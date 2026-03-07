import pandas as pd
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.model_selection import train_test_split
import joblib

class DatasetLoader:
    def __init__(self, data_path, scaler_path='scaler.pkl', encoder_path='label_encoder.pkl'):
        self.data_path = data_path
        self.scaler_path = scaler_path
        self.encoder_path = encoder_path
        self.label_encoder = LabelEncoder()
        self.scaler = StandardScaler()

    def load_and_preprocess(self, train_mode=True):
        df = pd.read_csv(self.data_path)
        X = df.drop(['timestamp', 'label'], axis=1)
        y = df['label']

        if train_mode:
            X_scaled = self.scaler.fit_transform(X)
            y_encoded = self.label_encoder.fit_transform(y)
            joblib.dump(self.scaler, self.scaler_path)
            joblib.dump(self.label_encoder, self.encoder_path)
            return train_test_split(X_scaled, y_encoded, test_size=0.2, random_state=42)
        else:
            self.scaler = joblib.load(self.scaler_path)
            self.label_encoder = joblib.load(self.encoder_path)
            return self.scaler.transform(X), self.label_encoder.transform(y)
