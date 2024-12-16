<<<<<<< HEAD
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QDir>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QResizeEvent>

class ParisOlympicsAnalysis : public QWidget {
    Q_OBJECT

public:
    ParisOlympicsAnalysis(QWidget* parent = nullptr) : QWidget(parent), currentImageIndex(0) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        imageLabel = new QLabel(this);
        headingLabel = new QLabel(this);  // Initialize the heading label
        imageLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(imageLabel);

        headingLabel->setAlignment(Qt::AlignCenter);  // Align heading label
        layout->addWidget(headingLabel);               // Add to layout

        QPushButton* nextButton = new QPushButton("Next Image", this);
        connect(nextButton, &QPushButton::clicked, this, &ParisOlympicsAnalysis::showNextImage);
        layout->addWidget(nextButton);

        setLayout(layout);
        setWindowTitle("Paris Olympics Analysis");
        resize(800, 600);

        // Set the specific folder path directly in the code
        imageFolder = "D:/pic-bg";  // Set your desired folder path here
        loadImagesFromFolder();
    }

protected:
    void resizeEvent(QResizeEvent* event) override {
        QWidget::resizeEvent(event);
        if (!currentImage.isNull()) {
            // Scale the current image to fit the resized window
            imageLabel->setPixmap(currentImage.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }
    }

private slots:
    void showNextImage() {
        if (!images.isEmpty()) {
            currentImageIndex = (currentImageIndex + 1) % images.size();
            showImage(currentImageIndex);
        }
    }

private:
    void loadImagesFromFolder() {
        QDir dir(imageFolder);
        QStringList filters;
        filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif";
        images = dir.entryList(filters, QDir::Files);

        currentImageIndex = 0;
        if (!images.isEmpty()) {
            showImage(currentImageIndex);
        }
    }

    void showImage(int index) {
        if (index < 0 || index >= images.size()) {
            imageLabel->setText("No image available.");
            if (headingLabel) headingLabel->clear();  // Clear the heading if out of bounds
            return;
        }

        QString imagePath = QDir(imageFolder).filePath(images[index]);
        QPixmap pixmap(imagePath);

        if (pixmap.isNull()) {
            imageLabel->setText("Failed to load image: " + images[index]);
            if (headingLabel) headingLabel->clear();  // Clear heading if image fails to load
        } else {
            currentImage = pixmap;  // Store the current image
            imageLabel->setPixmap(currentImage.scaled(imageLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

            // Only set heading if it's initialized
            if (headingLabel) {
                headingLabel->setText(images[index].section('.', 0, 0));  // Show image name without extension
            }
        }
    }



    QLabel* imageLabel;
    QLabel* headingLabel;  // Heading label to display image name
    QPixmap currentImage;
    QStringList images;
    QString imageFolder;
    int currentImageIndex;

};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);


    ParisOlympicsAnalysis viewer;
    viewer.show();
    return app.exec();
}

#include "main.moc"
=======
#include "nocs.h"

int main()
{
    NocList nocsList;

    // Load data from the CSV file
    string filePath = "data/nocs.csv";
    nocsList.loadFromCSV(filePath);

    // Print the linked list
    //nocsList.printList();

    // Append a new row to the CSV and linked list
    //cout << "\nAdding a new entry to the CSV and linked list..." << endl;
    //nocsList.appendToCSVAndList(filePath, "NEW", "Newland", "Newlandia", "TestTag", "New note");

    // Print the updated linked list
    //cout << "\nUpdated Linked List Contents:" << endl;
    //nocsList.printList();

    // Delete a row from the CSV and linked list
    cout << "\nDeleting the entry with code 'NEW'..." << endl;
    nocsList.deleteFromCSVAndList(filePath, "NEW");

    // Print the linked list after deletion
    cout << "\nLinked List Contents After Deletion:" << endl;
    nocsList.printList();

    return 0;
}
>>>>>>> f8e8f257ada51c41ef6ef318667ca07c49a6bbd2
