# Image Steganography 

Image steganography is the process of hiding information inside of images; thus, making it invisible to the human eye. 

### Steganography vs Cryptography

Although steganography and cryptography both play a role in protecting data, they do so in distinct ways. Cryptography (encryption) transforms data into an unreadable format 
without a decryption key. Both symmetric (one key for encryption/decryption - ex. AES) and asymmetric (pair of keys for encryption/decryption - ex. RSA) forms of encryption manipulate the 
data and make it inaccessible without the appropriate key. However, Steganography does not transform the data but hides it entirely. This makes it seem as if there is no hidden data. 
This can reduce the chances of attack due to the hidden existence of data embedded in seemingly irrelevant data. 

### LSB Replacement

Can you spot the difference between these two images? 

| Raw      | Encoded  |
| -------- | ------- |
| <img src="./img/mona.png" width="300"> | <img src="./output/encoded.png" width="300">  |

The image on the right has an encoded message hidden inside the pixels: "hello world".

LSB (least significant bit) replacement is the common practice of hiding information in the LSB of pixels within an image. By replacing the LSB (the right-most bit), the change to the pixel does 
not register to the human eye; therefore, making it go unnoticed. 

For example: 
Take a look at the following images of red. 

| Pixel    | Binary  |
| -------- | ------- |
| ![image](https://github.com/HenryKim12/image-steganography/assets/113074781/77c514a6-b398-4cd1-b0b3-3023a9eb0b08)  | 1111 1111  |
| ![image](https://github.com/HenryKim12/image-steganography/assets/113074781/fc43f08a-1848-4752-a1f6-d0a62c2efc60)  | 1111 1110  |

Note the difference in their binary representations. The changed LSB makes minimal difference to the RGB value of the pixel. 

The LSB algorithm has two processes:
1. Encoding (encryption): Iterate through the image's pixels (as well as RGB channels) and modify the LSB of each pixel channel to match the bit (0 or 1) of the hidden message.
2. Decoding (decryption): Retrieve the LSB of every pixel channel to reconstruct the hidden message by combining the extracted LSB.

### Usage 

To encrypt a hidden message inside of the image, include a `.png` image and run the commands from the root directory.

Build project:
```
cmake -B build
cd build
make
```
Execute:
```
./img-sg ~/path-to-img <message-to-encode>

# Example:
./img-sg ../img/mona.png "hello world"
```

### License
This project is licensed under the [MIT License](https://github.com/HenryKim12/image-steganography/blob/main/LICENSE)

