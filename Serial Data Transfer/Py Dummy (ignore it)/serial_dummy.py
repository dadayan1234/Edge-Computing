import serial
import random
import time

# Inisialisasi koneksi serial
ser = serial.Serial('COM12', 9600)  # Ganti 'COM1' dengan port serial virtual yang Anda gunakan

def generate_random_data():
    return random.randint(2, 250)

def main():
    try:
        while True:
            data = generate_random_data()
            ser.write(str(data).encode())
            print(f"Data terkirim: {data}")

            time.sleep(1)

            # Setiap 5 detik, mengubah data secara acak
            if time.time() % 5 == 0:
                print("Mengubah data...")
                data = generate_random_data()
                ser.write(str(data).encode())
                print(f"Data terkirim: {data}")

            time.sleep(1)

    except KeyboardInterrupt:
        ser.close()
        print("Koneksi serial ditutup.")

if __name__ == "__main__":
    main()
