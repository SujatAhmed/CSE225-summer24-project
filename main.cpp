
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include <QDir>
#include <QPixmap>
#include <QScrollBar>

class ImageViewer : public QWidget {
public:
    explicit ImageViewer(const QString& imageDir, QWidget* parent = nullptr) : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        // Scroll area setup
        QScrollArea* scrollArea = new QScrollArea(this);
        QWidget* container = new QWidget();
        QVBoxLayout* containerLayout = new QVBoxLayout(container);

        // Load images from the directory
        QDir dir(imageDir);
        QStringList filters;
        filters << "*.png" << "*.jpg" << "*.jpeg" << "*.bmp" << "*.gif";
        dir.setNameFilters(filters);
        
        QStringList imageFiles = dir.entryList(QDir::Files);
        for (const QString& file : imageFiles) {
            QLabel* imageLabel = new QLabel();
            QPixmap pixmap(dir.absoluteFilePath(file));

            // Scale image to fit scroll area width while maintaining aspect ratio
            pixmap = pixmap.scaled(scrollArea->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

            imageLabel->setPixmap(pixmap);
            imageLabel->setAlignment(Qt::AlignCenter);
            containerLayout->addWidget(imageLabel);
        }

        container->setLayout(containerLayout);
        scrollArea->setWidget(container);
        scrollArea->setWidgetResizable(true);

        layout->addWidget(scrollArea);
        setLayout(layout);

        // Update image sizes when the scroll area resizes
        connect(scrollArea->horizontalScrollBar(), &QScrollBar::rangeChanged, this, [containerLayout, scrollArea]() {
            for (int i = 0; i < containerLayout->count(); ++i) {
                QLabel* imageLabel = qobject_cast<QLabel*>(containerLayout->itemAt(i)->widget());
                if (imageLabel && !imageLabel->pixmap().isNull()) {
                    QPixmap pixmap = imageLabel->pixmap();
                    pixmap = pixmap.scaled(scrollArea->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    imageLabel->setPixmap(pixmap);
                }
            }
        });
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Directory containing images
    QString imageDir = "/home/sujat/core/images/"; // Change this to your directory path

    ImageViewer viewer(imageDir);
    viewer.setWindowTitle("Graph and Chart Viewer");
    viewer.resize(800, 600);
    viewer.show();

    return app.exec();
}

